#include <iostream>
#include <fstream>
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

    if (!procuradorLeitura) return 0;

    int qtdLinhas = 0;
    string linha;
    while (!procuradorLeitura.eof()) {
		getline(procuradorLeitura,linha); //lendo a linha inteira
        if (linha == "") break;
		qtdLinhas++;
	}
    procuradorLeitura.close();
    return qtdLinhas;
}

void popularListaArquivo(Inscrito *lista, string nomeArquivo) {
    ifstream procuradorLeitura;
    procuradorLeitura.open(nomeArquivo);
    string nome, email;
    int i = 0;

    string linha;
    while (!procuradorLeitura.eof()) {
		getline(procuradorLeitura,linha); //lendo a linha inteira
        if (linha == "") break;

        int posicaoPontoVirgula = linha.find(";");
        nome = linha.substr(0, posicaoPontoVirgula);
        email = linha.substr(posicaoPontoVirgula + 1, 200);

        lista[i].nome = nome;
        lista[i].email = email;
        i++;
	}
    procuradorLeitura.close();
}

void exibirLista(Inscrito *lista, int qtdInscritos) {
    for (int i = 0; i < qtdInscritos; i++) {
        cout << "Nome: " << lista[i].nome << " Email: " << lista[i].email << endl;
    }
}


bool jaCadastrado(string nome, Inscrito *lista, int qtdInscritos) {
    for (int i = 0; i < qtdInscritos; i++) {
        if (lista[i].nome == nome) {
            return true;
        }
    }
    return false;
}

void cadastrarNaLista(Inscrito *lista, int *qtdInscritos, string nomeArquivo) {
    ofstream procuradorEscrita;
    string nome, email;
    procuradorEscrita.open(nomeArquivo, ios::out | ios::app);
    cout << "Inscrito sendo cadastrado na posicao " << *qtdInscritos << endl;
    do {
        cout << "Digite seu nome completo: ";
        getline(cin, nome);
        nome = paraMaiusculo(nome);
    } while (!validaNomeCompleto(nome));

    cout << "Digite seu email: ";
    cin >> email;


    //teria que verificar se esse par nome e email já estão na lista
    if (jaCadastrado(nome, lista, *qtdInscritos)) {
     cout << "Erro: Inscrito ja cadastrado no sistema\n";   
    } else {
        lista[*qtdInscritos].nome = nome;
        lista[*qtdInscritos].email = email;
        *qtdInscritos = *qtdInscritos + 1;

        //adicionar no final do arquivo
        procuradorEscrita << nome << ";" << email << endl;
    }

    procuradorEscrita.close();
}

void menu(Inscrito *listaInscritos, string *listaPresencas, 
int qtdInscritos, int qtdPresencas, string nomeArquivoInscritos, string nomeArquivoPresencas) {
    int opcao;
    int tecla;
    do {
        system("cls");
        cout << "MENU\n";
        cout << "1 - Realizar inscricao\n";
        cout << "2 - Listar Inscritos\n";
        cout << "3 - Registrar presenca\n";
        cout << "4 - Listar presentes\n";
        cout << "5 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
            cout << "INSCRICAO\n";
            cadastrarNaListaInscritos(listaInscritos, &qtdInscritos, nomeArquivoInscritos);
            break;
        case 2:
            cout << "LISTAGEM DE INSCRITOS\n";
            exibirListaInscritos(listaInscritos,qtdInscritos);
            break;
        case 3:
            cout << "REGISTRAR PRESENCA\n";
            cadastrarNaListaPresencas(listaPresencas, &qtdPresencas, nomeArquivoPresencas);
            break;
        case 4:
            cout << "LISTAGEM DE PRSENTES\n";
            exibirListaPresencas(listaPresencas,qtdPresencas);
            break;
        case 5:            
            break;
        default:
            cout << "Opcao invalida!!\n";
            break;
        }

        system("pause");
        
    } while (opcao != 3);
}


int main() {
    Inscrito *listaInscritos; //um inscrito, com nome, email e matricula
    string *listaPresencas; //somente a matricula dos presentes    
    int quantidadeInscritos;
    int quantidadePresencas;
    string nomeArquivoInscritos = "inscritos.csv";
    string nomeArquivoPresencas = "presencas.csv";

    quantidadeInscritos = contarLinhasArquivo(nomeArquivoInscritos);
    quantidadePresencas = contarLinhasArquivo(nomeArquivoPresencas);
    listaInscritos = (Inscrito*)malloc(sizeof(Inscrito) * (quantidadeInscritos + 100));
    listaPresencas = (string*)malloc(sizeof(string) * (quantidadePresencas + 100));

    //popular lista com dados do arquivo
    popularListaArquivoInscritos(listaInscritos,nomeArquivoInscritos);
    popularListaArquivoPresencas(listaPresencas,nomeArquivoPresencas);
    //chamar menu
    menu(listaInscritos, listaPresencas, quantidadeInscritos, quantidadePresencas, nomeArquivoInscritos, nomeArquivoPresencas);

    return 1;
}