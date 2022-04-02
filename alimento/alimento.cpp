#include "alimento.h"

using namespace std;

Alimento::Alimento() {
  id = -1;
  nome = "";
  marca = "";
  valorCalorico = 0;
  preco = 0;
}

void Alimento::cadastrar() {
  cout << "Voce selecionou cadastrar um novo alimento." << '\n';

  cout << "Digite o id: "; cin >> this->id; cout << '\n';
  cout << "Digite o nome: "; cin >> this->nome; cout << '\n';
  cout << "Digite a marca: "; cin >> this->marca; cout << '\n'; 
  cout << "Digite o valor calórico: "; cin >> this->valorCalorico; cout << '\n';
  cout << "Digite o preço: "; cin >> this->preco; cout << '\n';
  
}

int Alimento::getId(){
  return id;
}

int Alimento::getValorCalorico(){
  return valorCalorico;
}

string Alimento::getNome(){
  return nome;
}

void Alimento::setNome(string novoNome) {
  this->nome = novoNome;
}

string Alimento::getMarca(){
  return marca;
}

void Alimento::setMarca(string novaMarca) {
  this->marca = novaMarca;
}

void Alimento::setPreco(double novoPreco) {
  this->preco = novoPreco;
}

void Alimento::setValorCalorico(int novoValor) {
  this->valorCalorico = novoValor;
}

double Alimento::getPreco(){
  return preco;
}

int Alimento::procurar(vector<Alimento*> alimentos, int id){
  for(int i = 0; i < alimentos.size(); i++){
    if(alimentos[i]->getId() == id) return i;
  }
  return -1;
}

void Alimento::excluir(vector<Alimento*> *alimentos, int id){

  int index = Alimento::procurar(*alimentos, id);

  if(index != -1){
    alimentos->erase(alimentos->begin() + index);
    cout << "Alimento de id " << id << " apagado\n";
  }
  else{
    cout << "Alimento não encontrado\n";
  }
  
}

void Alimento::print() {
  cout << "ID: " << id << '\n';
  cout << "Nome: " << nome << '\n';
  cout << "Marca: " << marca << '\n';
  cout << "Valor calórico: " << valorCalorico << '\n';
  cout << "Preço: " << preco << '\n';
  cout << '\n';
}

int Alimento::validar(Alimento *alimento){

  int id = alimento->getId();
  int valorCalorico = alimento->getValorCalorico();
  double preco = alimento->getPreco();

  if(id >= 0 && valorCalorico >= 0 && preco >= 0) return 1;

  cout << "----------------------------";
  string msg = "\nTentativa de cadastro de alimento inválido\n";
  msg += "Nome alimento: " + alimento->getNome() + "\n";
  
  if(id < 0) msg += "O id é menor que zero.\n";
  if(valorCalorico < 0) msg += "A quantidade de viagens é menor que zero.\n";
  if(preco < 0) msg += "O preço é menor que zero.\n";

  cout << msg;

  Log::write(msg, "erro-cadastro-alimentos.log");

  return 0;
  
}
