#ifndef LOG_H
#define LOG_H
#include <string>

using namespace std;

class Log {
  public:
    static void write(string msg, string pathLogFile);
    static string getStrDataHora();
};

#endif
