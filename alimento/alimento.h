#ifndef ALIMENTO_H
#define ALIMENTO_H
#include "./../log/log.h"
#include <fstream>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Alimento {
    private:
        int id;
        int valorCalorico;
        double preco;
        string nome;
        string marca;
  public:
    Alimento();
    void cadastrar();
    void alterar();
    void print();
    int getId();
    int getValorCalorico();
    double getPreco();
    string getNome();
    string getMarca();
    static int validar(Alimento *alimento);
    static int procurar(vector<Alimento*> alimentos, int id);
    static void excluir(vector<Alimento*> *alimentos, int id);
};

#endif
