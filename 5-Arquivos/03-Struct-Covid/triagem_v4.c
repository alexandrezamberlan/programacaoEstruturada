#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

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
    char resultado[30];
} Atendimento;

int main() {
    setlocale(LC_ALL,"Portuguese");
    Atendimento vetor[TAM];
    char letra;
    int opcao;
    int i = 0;
    int iAux;

    int valor; 

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
                    if (i < TAM) {
                        //método que recebe os dados do atendimento
                        printf("Data do atendimento: ");
                        scanf("%s", vetor[i].data);
                        fflush(stdin);
                        printf("Nome...............: ");
                        scanf("%s", vetor[i].nome);
                        fflush(stdin);
                        printf("Idade..............: ");
                        scanf("%d", &vetor[i].idade);
                        fflush(stdin);
                        printf("Peso...........(kg): ");
                        scanf("%f", &vetor[i].peso);
                        fflush(stdin);
                        printf("Altura..........(m): ");
                        scanf("%f", &vetor[i].altura);
                        fflush(stdin);
                        vetor[i].imc = vetor[i].peso / (vetor[i].altura * vetor[i].altura);
                        vetor[i].resultadoTriagem = 0;

                        //método que recebe dados para triagem
                        printf("Tem febre? [1-Sim; 0-Não]: ");
                        scanf("%d", &valor);
                        fflush(stdin);
                        if (valor == 1) vetor[i].resultadoTriagem += 5; //vetor[i].resultadoTriagem = vetor[i].resultadoTriagem + 5;

                        printf("Tem dor de cabeça? [1-Sim; 0-Não]: ");
                        scanf("%d", &valor);
                        fflush(stdin);
                        if (valor == 1) vetor[i].resultadoTriagem += 1;

                        printf("Tem secreção nasal ou espirros? [1-Sim; 0-Não]: ");
                        scanf("%d", &valor);
                        fflush(stdin);
                        if (valor == 1) vetor[i].resultadoTriagem += 1;

                        printf("Tem dor ou irritação na garganta? [1-Sim; 0-Não]: ");
                        scanf("%d", &valor);
                        fflush(stdin);
                        if (valor == 1) vetor[i].resultadoTriagem += 1;

                        printf("Tem tosse seca? [1-Sim; 0-Não]: ");
                        scanf("%d", &valor);
                        fflush(stdin);
                        if (valor == 1) vetor[i].resultadoTriagem += 3;

                        printf("Tem dificuldade respiratória? [1-Sim; 0-Não]: ");
                        scanf("%d", &valor);
                        fflush(stdin);
                        if (valor == 1) vetor[i].resultadoTriagem += 10;

                        printf("Tem dores no corpo? [1-Sim; 0-Não]: ");
                        scanf("%d", &valor);
                        fflush(stdin);
                        if (valor == 1) vetor[i].resultadoTriagem += 1;

                        printf("Tem diarréia? [1-Sim; 0-Não]: ");
                        scanf("%d", &valor);
                        fflush(stdin);
                        if (valor == 1) vetor[i].resultadoTriagem += 1;

                        printf("Viajou, nos últimos 14 dias, para lugares com COVID confirmado? [1-Sim; 0-Não]: ");
                        scanf("%d", &valor);
                        fflush(stdin);
                        if (valor == 1) vetor[i].resultadoTriagem += 3;

                        printf("Esteve em contato, nos últimos 14 dias, com pessoas com COVID confirmado? [1-Sim; 0-Não]: ");
                        scanf("%d", &valor);
                        fflush(stdin);
                        if (valor == 1) vetor[i].resultadoTriagem += 10;

                        if (vetor[i].resultadoTriagem < 10) {
                            strcpy(vetor[i].resultado, "Risco Baixo");
                        } else if (vetor[i].resultadoTriagem < 20) {
                            strcpy(vetor[i].resultado, "Risco Médio");
                        } else {
                            strcpy(vetor[i].resultado, "Risco Alto");
                        }
                        //poderíamos mostrar ao digitador...
                        printf("Seu resultado é: %d com %s\n", vetor[i].resultadoTriagem, vetor[i].resultado);

                        i++;
                    } else {
                        printf("Lotou a estrutura de dados para atendimentos.....\n");
                    }
                    break;
            case 2 :system("clear");//para o windows use system("cls");
                    printf("LISTAGEM DE ATENDIMENTOS\n");
                    //método listar atendimentos
                    if (i == 0) {
                        printf("Estrutura vazia...\n");
                    } else {
                        for (iAux = 0; iAux < i; iAux++) {
                            printf("Data atendimento: %s\n", vetor[iAux].data);
                            printf("Nome............: %s\n", vetor[iAux].nome);
                            printf("Idade...........: %d\n", vetor[iAux].idade);
                            printf("Peso kg.........: %.1f\n", vetor[iAux].peso);
                            printf("Altura m........: %.1f\n", vetor[iAux].altura);
                            printf("IMC.............: %.1f\n", vetor[iAux].imc);
                            printf("Resultado: %d com %s\n", vetor[iAux].resultadoTriagem, vetor[iAux].resultado);
                            printf("---------------------------\n");
                        }
                    }
                    break;
            case 3 :system("clear");//para o windows use system("cls");
                    printf("PESQUISA POR ATENDIMENTO\n");
                    //método pesquisar por atendimento
                     if (i == 0) {
                        printf("Estrutura vazia...\n");
                    } else {
                        char nome[100];
                        int encontrou = 0;
                        printf("Digite nome paciente a pesquisar: ");
                        scanf("%s", nome);
                        fflush(stdin);
                        for (iAux = 0; iAux < i; iAux++) {
                            if (strcasecmp(nome, vetor[iAux].nome) == 0) {
                                encontrou = 1;
                                printf("Data atendimento: %s\n", vetor[iAux].data);
                                printf("Nome............: %s\n", vetor[iAux].nome);
                                printf("Idade...........: %d\n", vetor[iAux].idade);
                                printf("Peso kg.........: %.1f\n", vetor[iAux].peso);
                                printf("Altura m........: %.1f\n", vetor[iAux].altura);
                                printf("IMC.............: %.1f\n", vetor[iAux].imc);
                                printf("Resultado: %d com %s\n", vetor[iAux].resultadoTriagem, vetor[iAux].resultado);
                                printf("---------------------------\n");
                            }
                        }
                        if (encontrou == 0) {
                            printf("Atendimento não localizado na base....\n");
                        } 
                    }
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