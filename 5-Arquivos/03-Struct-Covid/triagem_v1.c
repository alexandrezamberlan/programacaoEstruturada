#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 5

//struct para comportar um atendimento de triagem
typedef struct {
    char data[11]; 
    char nome[100];
    int idade;
    float peso;
    float altura;
    float imc;
    int resultadoTriagem;
} Atendimento;

int main() {
    setlocale(LC_ALL,"Portuguese");
    Atendimento vetor[TAM];
    char letra;
    int opcao;
    do {
        //menu
        system("clear");//para o windows use system("cls");
        printf("Menu para triagem COVID\n");
        printf("1 - Cadastrar atendimento\n");
        printf("2 - Listar atendimentos\n");
        printf("3 - Pesquisar por atendimento\n");
        printf("4 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1 :system("clear");//para o windows use system("cls");
                    printf("CADASTRO DE ATENDIMENTO\n");
                    //método cadastrar atendimento
                    break;
            case 2 :system("clear");//para o windows use system("cls");
                    printf("LISTAGEM DE ATENDIMENTOS\n");
                    //método listar atendimentos
                    break;
            case 3 :system("clear");//para o windows use system("cls");
                    printf("PESQUISA POR ATENDIMENTO\n");
                    //método pesquisar por atendimento
                    break;
            case 4 :system("clear");//para o windows use system("cls");
                    printf("Obrigado por usar o sistema....\n");
                    break;
            default: printf("Opção inválida.....\n");
        }
        //system("pause"); para quem está no windows
        printf("Tecle enter para continuar: ");
        letra = getchar();
        fflush(stdin);

    } while (opcao != 4);
    return 1;
}