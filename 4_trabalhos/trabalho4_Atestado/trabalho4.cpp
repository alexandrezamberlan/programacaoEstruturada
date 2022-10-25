#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "util.h"

typedef struct {
  string nome;
  string email;
  string matricula;
} Inscrito;

int contarLinhasArquivo(string nomeArquivo) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);

  if (!procuradorLeitura)
    return 0;

  int qtdLinhas = 0;
  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;
    qtdLinhas++;
  }
  procuradorLeitura.close();
  return qtdLinhas;
}

void popularListaArquivoInscritos(Inscrito *lista, string nomeArquivo) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);
  string nome, email, matricula;
  int i = 0;

  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;

    int posicaoPrimeiroPontoVirgula = linha.find(";");
    int posicaoUltimoPontoVirgula = linha.find_last_of(";");
    cout << linha << endl;
    cout << "posicaoUltimoPontoVirgula: " << posicaoUltimoPontoVirgula << endl;

    nome = linha.substr(0, posicaoPrimeiroPontoVirgula);
    email = linha.substr(posicaoPrimeiroPontoVirgula + 1,
                         posicaoUltimoPontoVirgula -
                             (posicaoPrimeiroPontoVirgula + 1));
    matricula = linha.substr(posicaoUltimoPontoVirgula + 1, 200);

    lista[i].nome = nome;
    lista[i].email = email;
    lista[i].matricula = matricula;
    i++;
  }
  procuradorLeitura.close();
}

void popularListaArquivoPresencas(string *lista, string nomeArquivo) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);
  string matricula;
  int i = 0;

  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;

    int posicaoPrimeiroPontoVirgula = linha.find(";");

    matricula = linha.substr(0, posicaoPrimeiroPontoVirgula);

    lista[i] = matricula;

    i++;
  }
  procuradorLeitura.close();
}

void exibirListaInscritos(Inscrito *lista, int qtdInscritos) {
  for (int i = 0; i < qtdInscritos; i++) {
    cout << "Matricula: " << lista[i].matricula << ". Nome: " << lista[i].nome
         << ". Email: " << lista[i].email << endl;
  }
}

void exibirListaPresencas(string *lista, int qtdPresencas) {
  for (int i = 0; i < qtdPresencas; i++) {
    cout << "Matricula: " << lista[i] << endl;
  }
}

bool jaCadastrado(string email, Inscrito *lista, int qtdInscritos) {
  for (int i = 0; i < qtdInscritos; i++) {
    if (lista[i].email == email) {
      return true;
    }
  }
  return false;
}

bool jaCadastradoMatricula(string matricula, string *lista, int qtdPresencas) {
  for (int i = 0; i < qtdPresencas; i++) {
    if (lista[i] == matricula) {
      return true;
    }
  }
  return false;
}

void cadastrarNaListaInscritos(Inscrito *lista, int *qtdInscritos,
                               string nomeArquivo) {
  ofstream procuradorEscrita;
  string nome, email, matricula;
  procuradorEscrita.open(nomeArquivo, ios::out | ios::app);
  cout << "Inscrito sendo cadastrado na posicao " << *qtdInscritos << endl;
  do {
    cout << "Digite seu nome completo: ";
    getline(cin, nome);
    nome = paraMaiusculo(nome);
  } while (!validaNomeCompleto(nome));

  cout << "Digite seu email: ";
  cin >> email;

  cout << "Digite sua matricula: ";
  cin >> matricula;

  // teria que verificar se esse par nome e email já estão na lista
  if (jaCadastrado(email, lista, *qtdInscritos)) {
    cout << "Erro: Email ja cadastrado no sistema\n";
  } else {
    lista[*qtdInscritos].nome = nome;
    lista[*qtdInscritos].email = email;
    lista[*qtdInscritos].matricula = matricula;
    *qtdInscritos = *qtdInscritos + 1;
    // adicionar no final do arquivo
    procuradorEscrita << nome << ";" << email << ";" << matricula << endl;
  }
  procuradorEscrita.close();
}

void cadastrarNaListaPresencas(string *lista, int *qtdPresencas,
                               string nomeArquivo) {
  ofstream procuradorEscrita;
  string matricula, data;

  do {
    procuradorEscrita.open(nomeArquivo, ios::out | ios::app);
    cout << "Presenca sendo cadastrado na posicao " << *qtdPresencas << endl;
    cout << "vai que é tua\n";
    cout << "Digite sua matricula (-27 para sair): ";
    cin >> matricula;
    if (matricula == "-27") {
      procuradorEscrita.close();
      return;
    }

    if (jaCadastradoMatricula(matricula, lista, *qtdPresencas)) {
      cout << "Erro: Matrícula ja registrada no evento\n";
    } else {
      time_t t = time(nullptr);
      tm *now = localtime(&t);

      string dia = to_string(now->tm_mday);
      string mes = to_string(now->tm_mon + 1);
      string ano = to_string(now->tm_year + 1900);

      lista[*qtdPresencas] = matricula;
      *qtdPresencas = *qtdPresencas + 1;

      // adicionar no final do arquivo
      procuradorEscrita << matricula << ";" << dia << "/" << mes << "/" << ano
                        << endl;
      procuradorEscrita.close();
    }
  } while (true);
}

void menu(Inscrito *listaInscritos, string *listaPresencas, int qtdInscritos,
          int qtdPresencas, string nomeArquivoInscritos,
          string nomeArquivoPresencas) {
  int opcao;
  int tecla;
  do {
    // system("clear");
    cout << "MENU\n";
    cout << "1 - Realizar inscricao\n";
    cout << "2 - Listar Inscritos\n";
    cout << "3 - Registrar presenca\n";
    cout << "4 - Listar presentes\n";
    cout << "5 - Sair\n";
    cout << "Opcao: ";
    cin >> opcao;
    cin.ignore();

    switch (opcao) {
    case 1:
      cout << "INSCRICAO\n";
      cadastrarNaListaInscritos(listaInscritos, &qtdInscritos,
                                nomeArquivoInscritos);
      break;
    case 2:
      cout << "LISTAGEM DE INSCRITOS\n";
      exibirListaInscritos(listaInscritos, qtdInscritos);
      break;
    case 3:
      cout << "REGISTRAR PRESENCA\n";
      cadastrarNaListaPresencas(listaPresencas, &qtdPresencas,
                                nomeArquivoPresencas);
      break;
    case 4:
      cout << "LISTAGEM DE PRSENTES\n";
      exibirListaPresencas(listaPresencas, qtdPresencas);
      break;
    case 5:
      break;
    default:
      cout << "Opcao invalida!!\n";
      break;
    }

    // system("sleep 10s");

  } while (opcao != 5);
}

int main() {
  Inscrito *listaInscritos; // um inscrito, com nome, email e matricula
  string *listaPresencas;   // somente a matricula dos presentes
  int quantidadeInscritos;
  int quantidadePresencas;
  string nomeArquivoInscritos = "inscritos.csv";
  string nomeArquivoPresencas = "presencas.csv";

  quantidadeInscritos = contarLinhasArquivo(nomeArquivoInscritos);
  quantidadePresencas = contarLinhasArquivo(nomeArquivoPresencas);
  listaInscritos =
      (Inscrito *)malloc(sizeof(Inscrito) * (quantidadeInscritos + 100));
  listaPresencas =
      (string *)malloc(sizeof(string) * (quantidadePresencas + 100));

  // popular lista com dados do arquivo ao iniciar o sistema
  popularListaArquivoInscritos(listaInscritos, nomeArquivoInscritos);
  popularListaArquivoPresencas(listaPresencas, nomeArquivoPresencas);
  // chamar menu
  menu(listaInscritos, listaPresencas, quantidadeInscritos, quantidadePresencas,
       nomeArquivoInscritos, nomeArquivoPresencas);

  return 1;
}
