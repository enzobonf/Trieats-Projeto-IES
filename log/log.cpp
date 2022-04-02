#include "log.h"
#include <fstream>
#include <iostream>
//#include <string>
#include <sstream>
#include <time.h>

using namespace std;

string Log::getStrDataHora(){

    int timezone = -3;
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);   
    data_hora_atual = gmtime(&segundos);

    int dia = data_hora_atual->tm_mday, mes = data_hora_atual->tm_mon + 1,
    ano = data_hora_atual->tm_year + 1900;

    int hora = (data_hora_atual->tm_hour + timezone), minuto = data_hora_atual->tm_min,
    segundo = data_hora_atual->tm_sec;

    stringstream stream; char s[22] = ""; 
    string str = "Data: ";
    sprintf(s, "%02d/%02d/%04d %02d:%02d:%02d\n", dia, mes, ano, hora, minuto, segundo);

    stream << s;
    str += stream.str();

    return str;
}

string Log::getStrDataISO(){

    int timezone = -3;
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);   
    data_hora_atual = gmtime(&segundos);

    int dia = data_hora_atual->tm_mday, mes = data_hora_atual->tm_mon + 1,
    ano = data_hora_atual->tm_year + 1900;

    int hora = (data_hora_atual->tm_hour + timezone), minuto = data_hora_atual->tm_min,
      segundo = data_hora_atual->tm_sec;

    stringstream stream; char s[23] = ""; 
    string str;
    sprintf(s, "%04d-%02d-%02dT%02d:%02d:%02d", ano, mes, dia, hora, minuto, segundo);

    stream << s;
    str += stream.str();

    return str;
}

void Log::write(string msg, string pathLogFile){ 
    string strDataHoraLog = getStrDataHora();
    ofstream fout(pathLogFile, std::ios_base::app);
    fout.write(msg.c_str(), msg.size() * sizeof(char));
    fout.write(strDataHoraLog.c_str(), strDataHoraLog.size() * sizeof(char));
    fout.write("\n", sizeof(char));

    cout << "\n----------LOG SALVO----------\n";
  
}