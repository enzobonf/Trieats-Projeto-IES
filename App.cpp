#include "App.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void App::run(){
  introducao();
  menuGeral();
}

void App::introducao () {
  cout << "Trabalho 2 IES" << '\n';
  cout << "Alunos: Marcos Kalb, Enzo Bonfante"   << '\n';  
}

void App::menuGeral() {
  int x = 1;

  while(x){
    cout << "Menu geral:\n";
    cout << "\nDigite 1 para acessar o menu relacionado à clientes"  << '\n';
    cout << "Digite 2 para acessar o menu relacionado à alimentos" << '\n'; 
    cout << "Digite 3 para gerar um relatório" << '\n';
    cout << "Digite 0 para sair" << '\n';
    cin  >> x; cout << '\n';

    switch(x){
      case 1:
      {
        menuClientes();
        break;
      }

      case 2:
      {
        menuAlimentos();
        break;
      }
      
      case 0:
      {
        cout << "Saindo do programa\n";
        break;
      }
    }
  }
}

void App::menuClientes(){

  int x = 1;
  
  while(x){
    cout << "Menu de clientes:\n";
    cout << "\nDigite 1 para cadastrar um cliente"   << '\n';
    cout << "Digite 2 para alterar um cliente"  << '\n'; 
    cout << "Digite 3 para deletar um cliente"  << '\n'; 
    cout << "Digite 4 para listar os clientes"  << '\n'; 
    cout << "Digite 5 para salvar os clientes"  << '\n'; 
    cout << "Digite 0 para sair deste menu"     << '\n';
    cin  >> x;

    cout << '\n';

    switch(x){

      case 1:
      {
        cadastrarCliente();
        break;
      }
      
      case 2:
      {
        alterarCliente();
        break;
      }
      
      case 3: {
        excluirCliente();
        break;
      }
      
      case 4: {
        listarClientes();
        break;
      }
      
      case 5: {
        Cliente::salvarNoArquivo(clientes, "clientes.dat");
        break;
      }
      
    }
    
  }
  
} 

void App::menuAlimentos(){

  int x = 1;
  
  while(x){
    cout << "Menu de alimentos:\n";
    cout << "\nDigite 1 para cadastrar um alimento"   << '\n';
    cout << "Digite 2 para deletar um alimento"  << '\n'; 
    cout << "Digite 3 para listar os alimentos"  << '\n'; 
    cout << "Digite 0 para sair deste menu"     << '\n';
    cin  >> x;

    cout << '\n';

    switch(x){

      case 1:
      {
        cadastrarAlimento();
        break;
      }
      
      case 2: {
        excluirAlimento();
        break;
      }
      
      case 3: {
        listarAlimentos();
        break;
      }
      
      case 4: {
        //Alimento::salvarNoArquivo(alimentos, "clientes.dat");
        break;
      }
      
    }
    
  }
  
} 

void App::cadastrarCliente(){

  Cliente *cliente = new Cliente();
  cliente->cadastrar();
  
  if(Cliente::validar(cliente)){
    clientes.push_back(cliente);
    cout << "Cliente cadastrado com sucesso\n";
  }
}

void App::cadastrarAlimento(){

  Alimento *alimento = new Alimento();
  alimento->cadastrar();

  if(Alimento::validar(alimento)){
    alimentos.push_back(alimento);
    cout << "Alimento cadastrado com sucesso\n";
  }


}

void App::listarClientes(){
  cout << "---------Listagem de Clientes---------\n";
  for(auto& cliente: clientes){
    cliente->print();
  }
  if(!clientes.size()) cout <<  "\nNenhum cliente cadastrado\n\n";
  cout << "--------------------------------------\n";
}

void App::listarAlimentos(){
  cout << "---------Listagem de Alimentos---------\n";
  for(auto& alimento: alimentos){
    alimento->print();
  }
  if(!alimentos.size()) cout <<  "\nNenhum alimento cadastrado\n\n";
  cout << "--------------------------------------\n";
}

void App::excluirCliente(){
  int id;
  cout << "Digite o id do cliente a ser excluído: ";
  cin >> id;
  if(id < 0){
    cout << "O id deve ser um número positivo";
    return;
  }

  Cliente::excluir(&clientes, id);
}

void App::excluirAlimento(){
  int id;
  cout << "Digite o id do alimento a ser excluído: ";
  cin >> id;
  if(id < 0){
    cout << "O id deve ser um número positivo";
    return;
  }

  Alimento::excluir(&alimentos, id);
}

void App::alterarCliente(){

  int id;
  cout << "Digite o id do cliente a ser alterado: ";
  cin >> id;
  if(id < 0){
    cout << "O id deve ser um número positivo";
    return;
  }

  cout << "Qual campo do cliente você deseja alterar?\n\n";
  cout << "1 - Nome\n2 - Data de Nascimento\n3 - Quantidade de viagens\n\n";

  
  
}
