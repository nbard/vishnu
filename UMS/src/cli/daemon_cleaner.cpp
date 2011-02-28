#include "daemon_cleaner.hpp"
#include "sessionUtils.hpp"
#include "api_ums.hpp"


bfs::path home_dir;
bfs::path session_dir;
bfs::path vishnu_dir;
bfs::path daemon_file;
bfs::path proc_dir("/proc");
<<<<<<< HEAD
=======
const char *lockname = "vishnu3";
>>>>>>> 3dc789a34e819c422df91152128d28aa4c999731

bool pid_exists(const std::string& pid)
{
  extern bfs::path proc_dir;
  bfs::path token(proc_dir);
  token /= pid;
  return bfs::exists(token);
}



void deleter()
{

  extern bfs::path daemon_file;
  extern bfs::path session_dir;


  bi::file_lock f_lock(daemon_file.string().c_str());

  {
    bi::scoped_lock<bi::file_lock> lock(f_lock,bi::try_to_lock_type());

    if (false == lock.owns()) {
      std::cout << "cleaning process: already running" << std::endl;
      exit(EXIT_SUCCESS);
    }

    while(true) {

      bfs::directory_iterator it = bfs::directory_iterator(session_dir);

      for (; it != bfs::directory_iterator(); ++it) {// loop over session directory

        const bfs::path current_path = it->path();

        std::string pid = (current_path.filename()).string();


        if (!pid_exists(pid)) {

          // close all sessions opened by disconnect mode before deleting file

<<<<<<< HEAD
          SessionContainer allSessions=getAllSessions(current_path.string());// get all sessions stored in file

          if (false==allSessions.empty()){ // is there a session?

            BOOST_FOREACH (const SessionEntry& session, allSessions){

              if(2==session.getClosePolicy()) {//that session is open by disconnect mode

                close (session.getSessionKey()); // and need to be closed

              }

            }// end of looping over the file
=======
          BOOST_FOREACH (const SessionEntry& session, allSessions){
           std::cout << "closePolicy: "<< session.getClosePolicy() << std::endl;
 
            if(2==session.getClosePolicy()) {// session open with CLOSE_ON_DISCONNECT mode
>>>>>>> 3dc789a34e819c422df91152128d28aa4c999731

          }

          bfs::remove(current_path);// remove the file 

        }
      }
      btt::sleep(bpt::seconds(5));// take a pause
    }


    exit(EXIT_SUCCESS);

  }
}





void cleaner()
{
  // declare all global variables
  extern bfs::path home_dir;
  extern bfs::path session_dir;
  extern bfs::path vishnu_dir;
  extern bfs::path daemon_file;


  home_dir = getenv("HOME"); // set the user home directory
  vishnu_dir = home_dir ;  // set the directory in which will be stored the daemon lock file

  vishnu_dir /= ".vishnu";
  daemon_file=vishnu_dir;
  session_dir /= vishnu_dir;   // set the directory in which will be stored all session files



  daemon_file/="daemon.pid";



  session_dir /= "sessions";


  if (false==bfs::exists(vishnu_dir)){ // make sure vishnu_dir exists 

    bfs::create_directories(vishnu_dir);

  }


  if (false==bfs::exists(daemon_file)){ // make sure daemon_file exists

    bfs::ofstream f (daemon_file);

    f<<getpid();    // record daemon pid

    f.close();

  }


  pid_t pid = fork();// create a process resident to delete and close  all sessions corresponding on close terminal

  if (pid < 0) {
    std::cerr << "cleaning process: fork() failed" << std::endl;
  } else if (0 == pid) {
    deleter();
  }

  return;
}

