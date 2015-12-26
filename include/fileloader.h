#ifndef FILELOADER_H
#define FILELOADER_H

#include <iostream>
#include <fstream>

class FileLoader {
private:
  std::string m_data;

public:
  FileLoader(const std::string& fileName);

  std::string* GetData();
};

#endif
