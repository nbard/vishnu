/**
 * \file SessionProxy.cpp
 * \brief This file contains the VISHNU SessionProxy class.
 * \author Daouda Traore (daouda.traore@sysfera.com)
 * \date February 2011
 */
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <unistd.h>

#include "SessionProxy.hpp"
#include "UserProxy.hpp"
#include "UMSVishnuException.hpp"
#include "utilsClient.hpp"
#include "vishnu_version.hpp"
#include "utilVishnu.hpp"

/**
 * \fn explicit SessionProxy(const std::string& sessionKey)
 * \param sessionKey The encrypted identifier of the session generated by VISHNU
 * \brief Constructor, raises an exception on error
 */
SessionProxy::SessionProxy(const std::string& sessionKey):msessionKey(sessionKey)
{
}

/**
 * \fn explicit SessionProxy(const UMS_Data::Session& session)
 * \param session The object which encapsulates the session information (ex: identifier of the session)
 * \brief Constructor, raises an exception on error
 */
SessionProxy::SessionProxy(const UMS_Data::Session& session):msession(session)
{
}

/**
 * \fn SessionProxy()
 * \brief Constructor, raises an exception on error
 */
SessionProxy::SessionProxy()
{
}

/**
 * \brief Function to combine connect() and reconnect() into one function
 * \fn  _connect(const UserProxy& user,
 *               bool connect = false,
 *               const UMS_Data::ConnectOptions& options=UMS_Data::ConnectOptions())
 * \param user The object which encapsulates the user information (ex: userId and password)
 * \param connect to select the call of connect or reconnect function
 * \param options the object which encapsulate the options available for the connect method. It allows the user
 *  to choose the way for way for closing the session automatically on TIMEOUT or on DISCONNECT and the
 *  possibility for an admin to open a session as she was a specific user
 * \return raises an exception on error
 */
int SessionProxy::_connect(const UserProxy& user, bool connect, const UMS_Data::ConnectOptions& options)
{

  diet_profile_t* profile = NULL;
  char hostname[HOST_NAME_MAX_SIZE];
  std::string sshKey1;
  std::string sshKey2;
  std::string sshKey3;
  std::string sshKey4;
  std::string optionsToString;
  std::string versionToString;
  char* sessionInString;
  char* errorInfo;
  size_t length;
  char* key;
  char* encryptedKey;
  std::string msg = "call of function diet_string_set is rejected ";
  //To set the possibles paths of the ssh key
  sshKey1 = "/etc/ssh/ssh_host_dsa_key.pub";
  sshKey2 = "/etc/ssh/ssh_host_rsa_key.pub";
  sshKey3 = std::string(getenv("HOME"))+"/.vishnu/ssh_host_dsa_key.pub";
  sshKey4 = std::string(getenv("HOME"))+"/.vishnu/ssh_host_rsa_key.pub";
  gethostname(hostname, HOST_NAME_MAX_SIZE);

  std::ifstream ifile;
  std::ifstream ifile1(sshKey1.c_str());
  std::ifstream ifile2(sshKey2.c_str());
  std::ifstream ifile3(sshKey3.c_str());
  std::ifstream ifile4(sshKey4.c_str());

  bool checkFile1 = ifile1.is_open();
  bool checkFile2 = ifile2.is_open();
  bool checkFile3 = ifile3.is_open();
  bool checkFile4 = ifile4.is_open();
  //To check if at least on file can be oponed
  if(!checkFile1 && !checkFile2 && !checkFile3 && !checkFile4) {
    throw UMSVishnuException(ERRCODE_INVALID_PARAM, "can't open file "+sshKey1+" or "+sshKey2+" or "+sshKey3+":\n"+
        "You must copy the file of your sshKey in one of three free files:\n"
        +"/etc/ssh/ssh_host_dsa_key.pub, or\n"
        +"/etc/ssh/ssh_host_rsa_key.pub, or\n"
        +"$HOME/.vishnu/ssh_host_dsa_key.pub, or\n"
        +"$HOME/.vishnu/ssh_host_rsa_key.pub");
  }

  //To get the content of the first opened file and close the others files opened
  if(checkFile1) {
    ifile1.close();
    ifile.open(sshKey1.c_str());
    if(checkFile2) {
      ifile2.close();
    }
    if(checkFile3) {
      ifile3.close();
    }
    if(checkFile4) {
      ifile4.close();
    }
  } else if(checkFile2) {
    ifile2.close();
    ifile.open(sshKey2.c_str());
    if(checkFile3) {
      ifile3.close();
    }
    if(checkFile4) {
      ifile4.close();
    }
  } else if(checkFile3) {
    ifile3.close();
    ifile.open(sshKey3.c_str());
    if(checkFile4) {
      ifile4.close();
    }
  } else {
    ifile4.close();
    ifile.open(sshKey4.c_str());
  }

  ifile.seekg(0, std::ios::end);
  length = ifile.tellg();
  ifile.seekg(0, std::ios::beg);

  key = new char[length];
  ifile.read(key, length);
  ifile.close();

  std::string salt = "$6$"+user.getData().getUserId()+"$";
  encryptedKey = crypt(key, salt.c_str());

  UMS_Data::Version_ptr vers = vishnu::parseVersion(VISHNU_VERSION);
  if (vers == NULL) {
    throw UMSVishnuException(ERRCODE_INVALID_PARAM, "The format of the VISHNU VERSION is incorrect");
  } else {
    // SERIALIZE DATA MODEL
    ::ecorecpp::serializer::serializer _serializeVersion;
    //To serialize the version object in to versionToString
    versionToString =  _serializeVersion.serialize_str(vers);
  }

  if(connect) {
    // SERIALIZE DATA MODEL
    ::ecorecpp::serializer::serializer _ser;
    //To serialize the options object in to optionsToString
    optionsToString =  _ser.serialize_str(const_cast<UMS_Data::ConnectOptions_ptr>(&options));
    profile = diet_profile_alloc("sessionConnect", 5, 5, 7);
  } else {
    profile = diet_profile_alloc("sessionReconnect", 5, 5, 7);
  }

  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup((user.getData().getUserId()).c_str()), DIET_VOLATILE)) {
    msg += "with userId parameter "+user.getData().getUserId();
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(profile,1), strdup((user.getData().getPassword()).c_str()), DIET_VOLATILE)) {
    msg += "with password parameter";
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(profile,2), encryptedKey+salt.length(), DIET_VOLATILE)) {
    msg += "with sshKey parameter sshKey path";
    raiseDietMsgException(msg);
  }
  if(diet_string_set(diet_parameter(profile,3), hostname, DIET_VOLATILE)) {
    msg += "with hostname parameter "+std::string(hostname);
    raiseDietMsgException(msg);
  }
  if(connect) {
    if(diet_string_set(diet_parameter(profile,4), strdup(optionsToString.c_str()), DIET_VOLATILE)){
      msg += "with optionsToString parameter ";
      raiseDietMsgException(msg);
    }
  } else {
    if(diet_string_set(diet_parameter(profile,4), strdup((msession.getSessionId()).c_str()), DIET_VOLATILE)) {
      msg += "with sessionId parameter "+msession.getSessionId();
      raiseDietMsgException(msg);
    }
  }

  if(diet_string_set(diet_parameter(profile,5), strdup(versionToString.c_str()), DIET_VOLATILE)) {
      msg += "with version parameter "+versionToString;
      raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(profile,6), NULL, DIET_VOLATILE);
  diet_string_set(diet_parameter(profile,7), NULL, DIET_VOLATILE);

  if(!diet_call(profile)) {
    if(diet_string_get(diet_parameter(profile,6), &sessionInString, NULL)){
      msg += "by receiving sessionInString value";
      raiseDietMsgException(msg);
    }
    if(diet_string_get(diet_parameter(profile,7), &errorInfo, NULL)) {
      msg += "to receiving errorInfo message";
      raiseDietMsgException(msg);
    }
  } else {
    raiseDietMsgException("DIET call failure");
  }

  /*To raise a vishnu exception if the receiving message is not empty*/
  raiseExceptionIfNotEmptyMsg(errorInfo);

  UMS_Data::Session_ptr session_ptr;

  //To parse Session object serialized
  parseEmfObject(std::string(sessionInString), session_ptr, "Error by receiving Session object serialized");
  msession = *session_ptr;
  delete session_ptr;

  if (key!=NULL) {
    delete [] key;
  }

  if (vers != NULL) {
    delete vers;
  }

  return 0;
}

/**
 * \brief Function to open a session
 * \fn  int connect(const UserProxy& user, const UMS_Data::ConnectOptions& options)
 * \param user The object which encapsulates the user information (ex: userId and password)
 * \param options the object which encapsulate the options available for the connect method. It allows the user
 *  to choose the way for way for closing the session automatically on TIMEOUT or on DISCONNECT and the
 *  possibility for an admin to open a session as she was a specific user
 * \return raises an exception on error
 */
int SessionProxy::connect(const UserProxy& user, const UMS_Data::ConnectOptions& options)
{
  return _connect(user, true, options);
}

/**
 * \brief Function to reconnect to an opened session
 * \fn  int reconnect(const UserProxy& user)
 * \param user The object which encapsulates the user information (ex: userId and password)
 * \return raises an exception on error
 */
int SessionProxy::reconnect(const UserProxy& user)
{
  return _connect(user);
}

/**
 * \brief Function close an opened session
 * \fn  int close()
 * \return raises an exception on error
 */
int SessionProxy::close()
{

  char* errorInfo = NULL;
  std::string msg = "call of function diet_string_set is rejected ";

  std::string sessionKey =  msessionKey;

  diet_profile_t* profile = diet_profile_alloc("sessionClose", 0, 0, 1);
  //IN Parameters
  if(diet_string_set(diet_parameter(profile,0), strdup(sessionKey.c_str()), DIET_VOLATILE)) {
    msg += "with sessionKey parameter "+sessionKey;
    raiseDietMsgException(msg);
  }

  //OUT Parameters
  diet_string_set(diet_parameter(profile,1), NULL, DIET_VOLATILE);

  if(!diet_call(profile)) {
    if(diet_string_get(diet_parameter(profile,1), &errorInfo, NULL)) {
      msg += "by receiving errorInfo message";
      raiseDietMsgException(msg);
    }
  } else {
    raiseDietMsgException("DIET call failure");
  }

  /*To raise a vishnu exception if the receiving message is not empty*/
  raiseExceptionIfNotEmptyMsg(errorInfo);

  diet_profile_free(profile);

  return 0;
}

/**
 * \brief Function get the encrypted identifier of the session generated by VISHNU
 * \fn std::string getSessionKey() const
 * \return the encrypted identifier of the session generated by VISHNU
 * \return raises an exception on error
 */
std::string SessionProxy::getSessionKey() const
{
  return msessionKey;
}

/**
 * \brief Function get machine information
 * \fn  UMS_Data::Session getData()
 * \return Session object encapsulates the information of the session
 * \return raises an exception on error
 */
UMS_Data::Session SessionProxy::getData() const
{
  return msession;
}

/**
 * \fn ~SessionProxy()
 * \brief Destructor, raises an exception on error
 */
SessionProxy::~SessionProxy()
{
}
