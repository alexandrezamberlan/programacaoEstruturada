#include <iostream>
#include <string>
#include <cstdlib>
#define TAM 10

using namespace std;

typedef struct {
    string placa;
    string dataE;
    string horaE;
    string horaS;
    int tempoPermanecia;
    float valor;
} Garagem;

int main() {
    int opcao;
    Garagem lista[TAM];
    int totalVeiculos = 0;

    //processo de inicialização da lista
    for (int i = 0; i < TAM; i++) {
        lista[i].placa = "";
        lista[i].dataE = "";
        lista[i].horaE = "";
        lista[i].horaS = "";
        lista[i].tempoPermanecia = 0;
        lista[i].valor = 0.0;
    }
    
    do {
        system("cls");
        cout << "Menu Garagem\n";
        cout << "1 - Entrada veiculo\n";
        cout << "2 - Saida veiculo\n";
        cout << "3 - Lista veiculos em garagem\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Entrando veiculo....\n";
            if (totalVeiculos == TAM) {
                cout << "Garagem lotada\n";
            } else {
                int i;
                //processo que localiza uma vaga disponível na lista
                for (i = 0; i < TAM; i++) {
                    if (lista[i].placa == "") {
                        break;
                    }
                }
                // for (int i = 0; i < TAM && lista[i].placa != ""; i++);
                //inserir o carro na lista garagem
                cout << "Placa: ";
                cin >> lista[i].placa;

                cout << "Data entrada (dd/mm/aaaa): ";
                cin >> lista[i].dataE;

                cout << "Hora entrada (hh:mm): ";
                cin >> lista[i].horaE;

                totalVeiculos++;
            }
            break;
        case 2:
            cout << "Saindo veiculo....\n";
            if (totalVeiculos == 0) {
                cout << "Garagem vazia\n";
            } else {
                //desafio
                //solicitar a placa de veículo a ser retirado

                //procurar pela placa na lista garagem

                //se encontrado... inicializar as variáveis naquela posição

                //se nao encontrado .... avisar que veículo não está na garagem...
            }
            break;
        case 3:
            cout << "Listando garagem....\n";
            if (totalVeiculos == 0) {
                cout << "Garagem vazia\n";
            } else {
                for (int i = 0; i < TAM; i++) {
                    if (lista[i].placa != "") {
                        cout << "Veiculo: " << lista[i].placa << endl;
                        //exibir tempoPermanencia do veiculo ate o momento
                    }
                }
            }
            break;
        case 4:
            cout << "Obrigado por usar o sistema\n";            
            break;
        
        default:
            cout << "Opcao invalida!\n";
            break;
        }
        system("pause");
    } while (opcao != 4);
    return 1;
}
