#include <iostream>
#include <string>
#include <cstdlib>

#define TAM 10
using namespace std;

typedef struct {
    int medida;
    string data;
    string hora;
} Glicemia;


int main() {
    Glicemia lista[TAM];
    int opcao;
    char letra;

    do {
        system("cls");
        cout << "MENU\n";
        cout << "1 - Inserir medida\n";
        cout << "2 - Listar medidas\n";
        cout << "3 - Consultar por data\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Inserir medida glicemica\n";

            break;
        case 2:
            cout << "Listar medidas glicemicas\n";

            break;
        case 3:
            cout << "Consultar por data\n";

            break;
        case 4:
            cout << "Obrigado por usar o sistema\n";

            break;
        default:
            cout << "Opcao invalida. Atencao\n";
            break;
        }
        system("pause");
        
    } while (opcao != 4);
    return 1;
}