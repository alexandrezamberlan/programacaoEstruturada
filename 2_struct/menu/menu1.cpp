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
    int iGlicemia = -1;

    int opcao;
    do {
        system("cls");
        cout << "Menu" << endl;
        cout << "1 - Cadastrar glicemia (nome paciente, data, valor glicemia)" << endl;
        cout << "2 - Listar glicemias (nome paciente, data, valor glicemia)" << endl;
        cout << "3 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        fflush(stdin);

        switch (opcao) {
            case 1:
                cout << "Cadastrar glicemia" << endl;
                if (iGlicemia == TAMANHO - 1) {
                    cout << "Nao e possivel cadastrar mais glicemias!" << endl;
                    break;
                }                
                cout << "Nome: ";
                iGlicemia++;
                getline(cin, glicemias[iGlicemia].nome);
                fflush(stdin);
                cout << "Data: ";
                cin >> glicemias[iGlicemia].data;
                fflush(stdin);
                cout << "Valor glicemia: ";
                cin >> glicemias[iGlicemia].valor;
                break;
            case 2:
                cout << "Listar glicemias" << endl;
                for (int i = 0; i <= iGlicemia; i++) {
                    cout << "Nome: " << glicemias[i].nome << endl;
                    cout << "Data: " << glicemias[i].data << endl;
                    cout << "Valor glicemia: " << glicemias[i].valor << endl;
                    cout << endl;
                }                
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