#include "../include/flags.h"

Flags::Flags(int argc, char** argv){
  m_argc = argc;
  m_argv = argv;
}

bool Flags::Parse(){
  // TODO: Write parsing function
  return true;
}

std::string Flags::GetString(std::string key){
  auto v = parsed[key];
  if(v.type != 1){
    return "";
  }

  return v.content;
}

int Flags::GetInt(std::string key){
  auto v = parsed[key];
  if(v.type != 2){
    return INT_MAX;
  }

  return atoi(v.content.c_str());
}

bool Flags::GetBool(std::string key){
  auto v = parsed[key];
  if(v.type != 3){
    return false;
  }

  return v.content.length() != 0;
}
