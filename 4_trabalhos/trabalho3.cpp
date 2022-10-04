#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
    cout << "Lista de Contatos\n";
    for (int i = 0; i < qtdContatos; i++) {
        cout << "Nome: " << lista[i].nome << " Email: " << lista[i].email << endl;
    }
}

void menu(Contato *lista, int qtdContatos) {
    int opcao;
    char tecla;
    do {
        system("clear");
        cout << "MENU\n";
        cout << "1 - Cadastrar contato\n";
        cout << "2 - Listar contatos\n";
        cout << "3 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "CADASTRO DE CONTATO\n";
            break;
        case 2:
            cout << "LISTAGEM DE CONTATOS\n";
            break;
        default:
            cout << "Opcao invalida!!\n";
            break;
        }

        cout << "Tecle enter para continuar!";
        
    } while (opcao != 5);
}


int main() {
    Contato *lista;
    int quantidadeContatos;

    //descobrir quantos elementos ha no arquivo, para definir o tamanho da lista
    quantidadeContatos = contarContatosArquivo("dadosTrab3.csv");
    lista = (Contato*)malloc(sizeof(Contato) * (quantidadeContatos + 100));

    //popular lista com dados do arquivo
    popularListaArquivo(lista,"dadosTrab3.csv");

    //chamar menu
    menu(lista, quantidadeContatos);

    return 1;
}