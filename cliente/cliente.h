#ifndef CLIENTE_H
#define CLIENTE_H
#include "./../log/log.h"
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <stdio.h>
#include <iostream>

using namespace std;

class Cliente {
    private:
        int id;
        int qnt_viagens;
        string nome;
        string data_nasc;
        vector<int> historico;
        vector<int> historico_atual;
  public:
    Cliente();
    void cadastrar();
    void print();
    int getId();
    int getQntViagens();
    string getNome();
    string getDataNasc();
    void setNome(string novoNome);
    void setDataNasc(string novaData);
    void setQntViagens(int novaQnt);
    static int validar(Cliente *cliente);
    static void salvarNoArquivo(vector<Cliente*> clientes, string fn);
    static int procurar(vector<Cliente*> clientes, int id);
    static void excluir(vector<Cliente*> *clientes, int id);
    /* static void listar(vector<Cliente*> clientes);
    static int findIndex(vector<Cliente*> clientes);
    static void excluir(vector<Cliente*> clientes, int id); */
};

#endif
