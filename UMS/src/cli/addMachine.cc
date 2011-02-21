

#include "addMachine.hh"
#include "utils.hh"
#include "machineUtils.hpp"
#include <boost/bind.hpp>

namespace po = boost::program_options;

using namespace std;

int main (int ac, char* av[]){




		/******* Parsed value containers ****************/

		string dietConfig;

		std::string machineDescription;

		std::string sessionKey;


		/********** EMF data ************/

		UMS_Data::Machine newMachine;


/**************** Callback functions *************/

		boost::function1<void,string> fName( boost::bind(&UMS_Data::Machine::setName,boost::ref(newMachine),_1));
		boost::function1<void,string> fSite( boost::bind(&UMS_Data::Machine::setSite,boost::ref(newMachine),_1));
		boost::function1<void,string> fLanguage( boost::bind(&UMS_Data::Machine::setLanguage,boost::ref(newMachine),_1));

		 boost::function1<void,string> fSshPublicKeyFile( boost::bind(&UMS_Data::Machine::setSshPublicKey,boost::ref(newMachine),_1));

		boost::shared_ptr<Options> opt= makeMachineOptions(av[0], fName,dietConfig, fSite,fLanguage,1);

				opt->add("sessionKey",
												"The session key",
												ENV,
												sessionKey);

				opt->add("sshPublicKeyFile,k",
                      "The the path to the SSH public key used by VISHNU to access local user accounts",
                        HIDDEN,
                        fSshPublicKeyFile,
												1);

				opt->setPosition("sshPublicKeyFile",1);


				try{
/**************  Parse to retrieve option values  ********************/

		opt->parse_cli(ac,av);

		opt->parse_env(env_name_mapper());

		opt->notify();



/********  Process **************************/


		checkVishnuConfig(*opt);

		cout << "Enter the Machine Description:\n ";

		getline(cin, machineDescription);

		newMachine.setMachineDescription(machineDescription);

/************** Call UMS connect service *******************************/

               // initializing DIET

							  if (diet_initialize(dietConfig.c_str(), ac, av)) {
                    cerr << "DIET initialization failed !" << endl;
               return 1;
              }

							 addMachine(sessionKey,newMachine);


	}// End of try bloc


				catch(po::required_option& e){// a required parameter is missing

					usage(*opt," name site language sshPublicKeyFile ","required parameter is missing");
  }
  catch(std::exception& e){

    errorUsage(av[0],e.what());

    return 1;
  }

  return 0;

}// end of main


