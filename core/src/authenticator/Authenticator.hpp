/**
 * \file Authenticator.hpp
 * \brief This file defines the authenticator object
 * \author Eugène PAMBA CAPO-CHICHI (eugene.capochichi@sysfera.com)
 * \date 15/12/11
 */

#ifndef _AUTHENTICATOR_H_
#define _AUTHENTICATOR_H_

#include "UMS_Data.hpp"

/**
 * \class Authenticator
 * \brief Authenticator
 */
class Authenticator {
public :
  /**
   * \brief Constructor
   */
  Authenticator();
  /**
   * \brief Destructor
   */
  virtual ~Authenticator();
   /**
  * \brief To authenticate a useer
  * \param user The user to authenticate
  * \return true if the corresponding user is
  * authenticated else false
  */
  virtual bool
  authenticate(UMS_Data::User& user) = 0;
};


#endif // _AUTHENTICATOR_H_
