/**
 * \file Mapper_imp.ccp
 * \brief Sample mapper
 * \author Kevin Coulomb (kevin.coulomb@sysfera.com)
 * \date 07/02/11
 */

#include "Mapper_impl.hpp"

Mapper_impl::Mapper_impl():Mapper(){
};

Mapper_impl::~Mapper_impl(){
};

Mapper_impl::Mapper_impl(MapperRegistry* reg, string na):Mapper(reg){
  mname = na;
  mmap.insert (pair<int, string>(1, "connect"));
  mmap.insert (pair<int, string>(2, "reconnect"));
  mmap.insert (pair<int, string>(3, "close"));
  mmap.insert (pair<int, string>(4, "addVishnuUser"));
  mmap.insert (pair<int, string>(5, "addLocalAccount"));
};

int
Mapper_impl::registerMapper(){
  mreg->addMapper(mname, this);
  return 0;
}

int
Mapper_impl::unregisterMapper(){
  return mreg->removeMapper(mname);
}

int
Mapper_impl::getCommand(const int& key,string& command){
  map<int, string>::const_iterator it;
  for (it = mmap.begin() ; it != mmap.end() ; it++){
    if (key==it->first){
      command = it->second;
      return 0;
    }
  }
}

int
Mapper_impl::getKey(const string& command, int& key){
  map<int, string>::const_iterator it;
  for (it = mmap.begin() ; it != mmap.end() ; it++){
    if (command.compare(it->second)==0){
      key = it->first;
      return 0;
    }
  }
}

int
Mapper_impl::code(const string& cmd, unsigned int code ) {
  return 0;
}

string
Mapper_impl::finalize(int key){
  return "";
}

string
Mapper_impl::decodeCPP (const string& msg){
  return "";
}
