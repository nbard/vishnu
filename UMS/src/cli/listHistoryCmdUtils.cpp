/**
 * \file listHistoryCmdUtils.cpp
 * \brief This file defines useful functions and types for the VISHNU list history
 *  command
 * \author Ibrahima Cisse (ibrahima.cisse@sysfera.com)
 */



#include "Options.hpp"

#include "listHistoryCmdUtils.hpp"
#include<iostream>
using namespace std;

/**
 * \brief To build options for the VISHNU list history command
 * \param pgName : The name of the command
 * \param fUserId: The user identifier option callback
 * \param dietConfig: Represents the VISHNU config file
 * \param fSessionId : The callback for the session identifier
 * \param fStartDateOption: The callback for the command start date option
 * \param fEndDateOption: The callback for the command end date option
 * \return The description of all options allowed by the command
 */
boost::shared_ptr<Options> 
makeListHistoryCmdOptions(std::string pgName,StringcallBackType& fUserId,std::string & dietConfig,
                          StringcallBackType& fSessionId,
                          LongcallBackType& fStartDateOption,
                          LongcallBackType& fEndDateOption){


  boost::shared_ptr<Options> opt(new Options(pgName));


  opt->add("dietConfig,c",
           "The diet config file",
           ENV,
           dietConfig);

  opt->add("adminListOption,a",
           "is an admin option for listing all commands of all users ",
           CONFIG);

  opt->add("userId,u",
           "an admin option for listing commands launched\n"
           "by a specific user identified by his/her userId",
           CONFIG,
           fUserId);

  opt->add("sessionId,i",
           "lists all commands launched within a specific session",
           CONFIG,
           fSessionId);

  opt->add("startDateOption,s",
           "allows the user to organize the commands listed\n"
           "by providing the start date\n"
           "(the UNIX timestamp  of the start date is used)",
           CONFIG,
           fStartDateOption);

  opt->add("endDateOption,e",
           "allows the user to organize the commands listed\n"
           "by providing the end date (the timestamp of the end date is used).\n"
           "By default, the end date is the current day",
           CONFIG,
           fEndDateOption);




  return opt;



}






