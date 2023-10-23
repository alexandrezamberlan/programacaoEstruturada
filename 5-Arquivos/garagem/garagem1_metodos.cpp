#include <iostream>
#include <string>

using namespace std;
#include "structs.h"
#include "util.h"

#define TAM 10



int main(){
    Veiculo vetor[TAM];
    int opcao, quantidadeCarros;
    

    inicializarVetor(vetor, TAM);
    quantidadeCarros = 0;

    do {
        system("cls");
        cout << "MENU\n";
        cout << "1 - Entrar na garagem\n";
        cout << "2 - Listar veiculos\n";
        cout << "3 - Remover da garagem\n";
        cout << "4 - Sair do sistema\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            quantidadeCarros = entrarGaragem(vetor, TAM, quantidadeCarros);
            break;
        case 2:
            listarGaragem(vetor, TAM, quantidadeCarros);
            break;
        case 3:
            quantidadeCarros = sairGaragem(vetor, TAM, quantidadeCarros);            
            break;
        case 4:
            /* code */
            break;
        
        default:
            cout << "Opcao Invalida!\n";
            break;
        }

        system("pause");
    } while(opcao != 4);

    return 1;
}
