#include "../controller/crud.h"

void menu(Pessoa vetor[], int n, int totalInscritos) {  
    int opcao;
    do {
        system("cls");
        cout << "MENU" << endl;
        cout << "1 - Inscrever amigo\n";
        cout << "2 - Listar amigos\n";
        cout << "3 - Gerar amigo secreto\n";
        cout << "4 - Sair\n";        
        cout << "Opcao: ";
        cin >> opcao;
        fflush(stdin);
        switch (opcao) {
        case 1:
            cout << "Inscrever amigo\n";
            totalInscritos = cadastrarPessoa(vetor, n, totalInscritos);
            break;
        case 2:
            cout << "Listar amigos\n";
            listarPessoas(vetor, totalInscritos);
            break;
        case 3:
            cout << "Gerar amigo secreto\n";
            gerarAmigoSecreto(vetor, totalInscritos);
            break;
        case 4:            
            exit(1);
            break;
        default:
            cout << "Opcao invalida\n";
            break;
        } 
        system("pause");
    } while (true);
}