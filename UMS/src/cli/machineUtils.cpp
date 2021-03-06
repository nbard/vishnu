/**
 * \file machineUtils.cpp
 * \brief This file defines useful functions and types for the VISHNU add
 * update and delte commands
 * \author Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */

#include <boost/shared_ptr.hpp>  // for shared_ptr
#include <string>                       // for string

#include "Options.hpp"
#include "localAccountUtils.hpp"

using namespace std;


/**
 * \brief To build options for the VISHNU machine commands
 * \param pgName : The name of the command
 * \param fName : The machine name option callback
 * \param configFile : Represents the VISHNU config file
 * \param fSite : The site name option callback
 * \param fLanguage : The language option callback
 * \param fMachineDescription : The machine description option callback
 * \param type : Indicates if it is an add or an update command, 0 means update, and 1 means add
 * \return The description of all options allowed by the command
 */


boost::shared_ptr<Options> makeMachineOptions(std::string pgName,StringcallBackType& fName,std::string & configFile,
                                              StringcallBackType & fSite, StringcallBackType& fLanguage,
                                              StringcallBackType& fMachineDescription,int type){

  boost::shared_ptr<Options> opt(new Options(pgName));


  opt->add("configFile,c",
           "VISHNU configuration file",
           ENV,
           configFile);


  Group_type group=CONFIG;


  if(type){// type =0 for "update function" and type=1 for "add function"

    group=HIDDEN;
  }


  opt->add("name,n",
           "The name of the machine",
           group,
           fName,
           type);

  if (type){
    opt->setPosition("name",1);
  }

  opt->add("site,s",
           "The location of the machine",
           group,
           fSite,
           type);

  if (type){
    opt->setPosition("site",1);
  }

  opt->add("language,l",
           "The language in which the description of the machine has been done",
           group,
           fLanguage,
           type);

  if (type){
    opt->setPosition("language",1);
  }

  opt->add("machineDescription,d",
           "The description of the machine",
           group,
          fMachineDescription,
          type);

  if(type){
    opt->setPosition("machineDescription",1);
  }




  return opt;



}
