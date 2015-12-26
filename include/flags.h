#ifndef FLAGS_H
#define FLAGS_H

#include <iostream>
#include <map>
#include <climits>

class Flags {
private:
  int m_argc;
  char** m_argv;

  struct data {
    unsigned char type; // 1: string, 2: int, 3: bool
    std::string content;
  };
  std::map<std::string,data> parsed;

public:
  Flags(int argc, char* argv[]);
  bool Parse();
  std::string GetString(std::string key);
  int GetInt(std::string key);
  bool GetBool(std::string key);
};

#endif
