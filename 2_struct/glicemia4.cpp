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

    int ultimaMedida = -1;

    string data;
    bool encontrei = false;

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
            cout << "Inserindo\n";
            if (ultimaMedida == TAM - 1) {
                cout << "Estrutura lotada!\n";                
            } else {
                ultimaMedida++;
                cout << "Informe a medida glicemica: ";
                cin >> lista[ultimaMedida].medida;
                do {
                    cout << "Digite a data da medida [dd/mm/aaaa]: "; 
                    cin >> lista[ultimaMedida].data;
                } while (lista[ultimaMedida].data.length() != 10);
                do {
                    cout << "Digite a hora da medida [hh:mm]: "; 
                    cin >> lista[ultimaMedida].hora;
                } while (lista[ultimaMedida].hora.length() != 5);
            }
            break;
        case 2:
            cout << "Listar medidas glicemicas\n";
            if (ultimaMedida == -1) {
                cout << "Estrutura vazia\n";
            } else {
                for (int i = 0; i <= ultimaMedida; i++) {
                    cout << "Glicemica: " << lista[i].medida << ". Data: " << lista[i].data << ". Hora: " << lista[i].hora << endl;
                }
            }
            break;
        case 3:
            cout << "Consultar por data\n";
            
            if (ultimaMedida == -1) {
                cout << "Estrutura vazia\n";
            } else {
                cout << "Digite uma data de pesquisa [dd/mm/aaaa]: ";
                cin >> data;

                for (int i = 0; i <= ultimaMedida; i++) {
                    if (data == lista[i].data) {
                        cout << "Glicemica: " << lista[i].medida << ". Data: " << lista[i].data << ". Hora: " << lista[i].hora << endl;
                        encontrei = true;
                    }
                }
                if (!encontrei) {
                    cout << "Nenhum registro encontrado!\n";
                }
            }
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