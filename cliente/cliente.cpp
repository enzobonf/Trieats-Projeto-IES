#include "cliente.h"

using namespace std;

Cliente::Cliente() {
  id = -1;
  nome = "";
  data_nasc = "";
  qnt_viagens = -1;
}

void Cliente::cadastrar() {
  
  cout << "Voce selecionou cadastrar um novo cliente." << '\n';

  cout << "Digite o id: "; cin >> id; cout << '\n';
  cout << "Digite o nome: "; cin >> nome; cout << '\n';
  cout << "Digite a data de nascimento: "; cin >> data_nasc; cout << '\n';
  cout << "Digite a quantidade de viagens: "; cin >> qnt_viagens; cout << '\n';
  
}

int Cliente::getId(){
  return id;
}

string Cliente::getNome(){
  return nome;
}

void Cliente::setNome(string novoNome) {
  this->nome = novoNome;
}


int Cliente::getQntViagens(){
  return qnt_viagens;
}

void Cliente::setQntViagens(int novaQnt) {
  this->qnt_viagens = novaQnt;
}

string Cliente::getDataNasc(){
  return data_nasc;
}

void Cliente::setDataNasc(string novaData) {
  this->data_nasc = novaData;
}

int Cliente::procurar(vector<Cliente*> clientes, int id){
  for(int i = 0; i < clientes.size(); i++){
    if(clientes[i]->getId() == id) return i;
  }
  return -1;
}

void Cliente::excluir(vector<Cliente*> *clientes, int id){

  int index = Cliente::procurar(*clientes, id);

  if(index != -1){
    clientes->erase(clientes->begin() + index);
    cout << "Cliente de id " << id << " apagado\n";
  }
  else{
    cout << "Cliente não encontrado\n";
  }
  
}

void Cliente::salvarNoArquivo(vector<Cliente*> clientes, string fn){

  string path = "./cliente/"+ fn;
  ofstream fout(path);
  
  if(!clientes.size()){
    cout << "Não há clientes cadastrados\n";
    return;
  }

  for(auto& cliente: clientes){

    string id_cliente = to_string(cliente->getId()) + '\n';
    string nome_cliente = cliente->getNome() + '\n';
    string data_nasc = cliente->getDataNasc() + '\n';

    string historico, historico_atual, strFinal;

    std::stringstream result;
    std::copy(cliente->historico.begin(), cliente->historico.end(), ostream_iterator<int>(result, ","));

    historico = "[" + result.str() + "]\n";  result.str("");
    
    std::copy(cliente->historico_atual.begin(), cliente->historico_atual.end(), ostream_iterator<int>(result, ", "));
    
    historico_atual = "[" + result.str() + "]\n";  result.str("");

    strFinal = id_cliente + nome_cliente + data_nasc + historico + historico_atual;
    
    fout.write(strFinal.c_str(), strFinal.length() * sizeof(char));
    fout.write("\n", sizeof(char));
  }

  cout << "Os " << clientes.size() << " clientes cadastrados foram salvos no arquivo "
    << path << '\n';
}

void Cliente::print() {
  cout << "ID: " << this->id << '\n';
  cout << "Nome: " << this->nome << '\n';
  cout << "Data Nascimento: " << this->data_nasc << '\n';
  cout << "Qnt. viagens: " << this->qnt_viagens << '\n';
  cout << '\n';
}

int Cliente::validar(Cliente *cliente){

  int id = cliente->getId();
  int qntViagens = cliente->getQntViagens();

  if(id >= 0 && qntViagens >= 0) return 1;

  cout << "----------------------------";
  string msg = "\nTentativa de cadastro de cliente inválido\n";
  msg += "Nome cliente: " + cliente->getNome() + "\n";
  
  if(id < 0) msg += "O id é menor que zero.\n";
  if(qntViagens < 0) msg += "A quantidade de viagens é menor que zero.\n";

  cout << msg;

  Log::write(msg, "erro-cadastro-clientes.log");

  return 0;
  
}