#include "fileloader.h"

FileLoader::FileLoader(const std::string& fileName){
  std::ifstream file;
  file.open(fileName.c_str());

  std::string line;

  if(file.is_open()){
    while(file.good()){
      getline(file, line);
      m_data += line + "\n";
    }
  } else {
    std::cerr << "Unable to open file " << fileName << std::endl;
  }
}

std::string* FileLoader::GetData(){
  return &m_data;
}
