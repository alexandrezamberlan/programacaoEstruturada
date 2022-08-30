#include <iostream> //cin e cout
#include <string> //
#define TAM 10
using namespace std; //omitir o std na frente do cin, por exemplo 

typedef struct {
    string nome;
    string email;
    string telefone; 
} Contato; //tipo artificial construido pelo programador

int main() {
    Contato vetor[TAM];
    int qtdContatos = 0;
    int opcao;
    //montar o menu
    do {
        system("cls");
        cout << "Agenda de Contatos - MENU\n";
        cout << "1 - Inserir\n";
        cout << "2 - Remover\n";
        cout << "3 - Atualizar\n";
        cout << "4 - Listar\n";
        cout << "5 - Pesquisar\n";
        cout << "6 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                cout << "INSERIR\n";

                break;
            case 2:
                cout << "REMOVER\n";

                break;
            case 3:
                cout << "ATUALIZAR\n";

                break;
            case 4:
                cout << "LISTAR\n";

                break;
            case 5:
                cout << "PESQUISAR\n";

                break;
            case 6:
                cout << "Obrigado por usar o sistema!\n";
                break;                
            default:
                cout << "Opcao invalida!\n";
                break;
        }
        system("pause");
    }  while (opcao != 6);
  
    return 1;
}