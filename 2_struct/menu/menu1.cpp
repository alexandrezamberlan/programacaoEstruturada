/*
Menu
1 - Cadastrar glicemia (nome paciente, data, valor glicemia)
2 - Listar glicemias (nome paciente, data, valor glicemia)
3 - Sair
Opção: 
*/

#include <iostream>
#include <vector>
#include <string>

#define TAMANHO 5

using namespace std;

typedef struct {
    string nome;
    string data;
    float valor;
} Glicemia;

int main() {
    vector<Glicemia> glicemias(TAMANHO);

    int opcao;
    do {
        system("cls");
        cout << "Menu" << endl;
        cout << "1 - Cadastrar glicemia (nome paciente, data, valor glicemia)" << endl;
        cout << "2 - Listar glicemias (nome paciente, data, valor glicemia)" << endl;
        cout << "3 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Cadastrar glicemia" << endl;

                break;
            case 2:
                cout << "Listar glicemias" << endl;
                
                break;
            case 3:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
        system("pause");
    } while (opcao != 3);

    return 1;
}