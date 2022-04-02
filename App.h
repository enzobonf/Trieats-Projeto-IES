#ifndef APP_H
#define APP_H
#include <vector>
#include "cliente/cliente.h"
#include "alimento/alimento.h"
#include "log/log.h"

class App {
private:
  std::vector<Cliente*> clientes;
  std::vector<Alimento*> alimentos;
  void menuGeral();
  void menuClientes();
  void menuAlimentos();
  void introducao();
public:
  void run();
  void cadastrarCliente();
  void cadastrarAlimento();
  void listarClientes();
  void listarAlimentos();
  void excluirCliente();
  void excluirAlimento();
  void alterarCliente();
  void alterarAlimento();
  void gerarRelatorio();
};

#endif