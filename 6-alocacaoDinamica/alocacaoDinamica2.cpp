// Menu
// 1 - Cadastrar
// 2 - Listar 
// 3 - Atualizar
// 4 - Deletar
// 5 - Sair
// Opção

#include <iostream>
#include <string>

using namespace std;

void listar(string *vetor, int qtdInseridos) {
    if (qtdInseridos == 0) {
        return;
    }
    cout << "LISTAR\n";
    for (int i = 0; i < qtdInseridos; i++) {
        cout << vetor[i] << endl;
    }
}


void cadastrar(string *vetor, int *qtdInseridos, int tamanho) {
    if (*qtdInseridos == tamanho) {
        return;
    }
    cout << "CADASTRAR\n";
    string nome;
    cout << "Nome: ";
    getline(cin, nome);
    vetor[*qtdInseridos] = nome;
    *qtdInseridos += 1;
}

void menu(string *vetor, int *qtdInseridos, int tamanho) {
    int op;
    do {
        system("cls");
        cout << "1 - Cadastrar\n";
        cout << "2 - Listar\n";
        cout << "3 - Atualizar\n";
        cout << "4 - Deletar\n";
        cout << "5 - Sair\n";
        cout << "Opcao: ";
        cin >> op;
        fflush(stdin);

        switch (op)
        {
            case 1:
                cadastrar(vetor, qtdInseridos, tamanho);
                break;
            case 2:
                listar(vetor, *qtdInseridos);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                return;
            default:
                cout << "Opcao invalida\n";
                break;
        }
        system("pause");
    } while (true);
}

int main() {
    string *vetor;
    int tamanho;
    int qtdInseridos = 0;

    cout << "Quantos nomes quer gerenciar: ";
    cin >> tamanho;

    vetor = (string *)malloc(sizeof(string) * tamanho);
    menu(vetor, &qtdInseridos, tamanho);

    return 1;
}