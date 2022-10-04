#include <iostream>
#include <fstream>
#include <string>
using namespace std;


#include "util.h"

typedef struct {
    string nome;
    string email;
} Contato;

int contarContatosArquivo(string nomeArquivo) {
    ifstream procuradorLeitura;
    procuradorLeitura.open(nomeArquivo);

    if (!procuradorLeitura) return 0;

    int qtdContatos = 0;
    string linha;
    while (!procuradorLeitura.eof()) {
		getline(procuradorLeitura,linha); //lendo a linha inteira
        if (linha == "") break;
		qtdContatos++;
	}
    procuradorLeitura.close();
    return qtdContatos;
}

void popularListaArquivo(Contato *lista, string nomeArquivo) {
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

void exibirLista(Contato *lista, int qtdContatos) {
    for (int i = 0; i < qtdContatos; i++) {
        cout << "Nome: " << lista[i].nome << " Email: " << lista[i].email << endl;
    }
}


bool jaCadastrado(string nome, Contato *lista, int qtdContatos) {
    for (int i = 0; i < qtdContatos; i++) {
        if (lista[i].nome == nome) {
            return true;
        }
    }
    return false;
}

void cadastrarNaLista(Contato *lista, int *qtdContatos, string nomeArquivo) {
    ofstream procuradorEscrita;
    string nome, email;
    procuradorEscrita.open(nomeArquivo, ios::out | ios::app);
    cout << "Contato sendo cadastrado na posicao " << *qtdContatos << endl;
    do {
        cout << "Digite seu nome completo: ";
        getline(cin, nome);
        nome = paraMaiusculo(nome);
    } while (!validaNomeCompleto(nome));

    cout << "Digite seu email: ";
    cin >> email;


    //teria que verificar se esse par nome e email já estão na lista
    if (jaCadastrado(nome, lista, *qtdContatos)) {
     cout << "Erro: contato ja cadastrado no sistema\n";   
    } else {
        lista[*qtdContatos].nome = nome;
        lista[*qtdContatos].email = email;
        *qtdContatos = *qtdContatos + 1;

        //adicionar no final do arquivo
    }
    procuradorEscrita << nome << ";" << email << endl;

    procuradorEscrita.close();
}

void menu(Contato *lista, int qtdContatos, string nomeArquivo) {
    int opcao;
    int tecla;
    do {
        system("cls");
        cout << "MENU\n";
        cout << "1 - Cadastrar contato\n";
        cout << "2 - Listar contatos\n";
        cout << "3 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
            cout << "CADASTRO DE CONTATO\n";
            cadastrarNaLista(lista, &qtdContatos, nomeArquivo);
            break;
        case 2:
            cout << "LISTAGEM DE CONTATOS\n";
            exibirLista(lista,qtdContatos);
            break;
        case 3:            
            break;
        default:
            cout << "Opcao invalida!!\n";
            break;
        }

        system("pause");
        
    } while (opcao != 3);
}


int main() {
    Contato *lista;
    int quantidadeContatos;
    string nomeArquivo = "dadosTrab3.csv";

    //descobrir quantos elementos ha no arquivo, para definir o tamanho da lista
    quantidadeContatos = contarContatosArquivo(nomeArquivo);
    lista = (Contato*)malloc(sizeof(Contato) * (quantidadeContatos + 100));

    //popular lista com dados do arquivo
    popularListaArquivo(lista,nomeArquivo);

    //chamar menu
    menu(lista, quantidadeContatos, nomeArquivo);

    return 1;
}