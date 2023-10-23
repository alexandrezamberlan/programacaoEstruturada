#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

//struct para comportar um atendimento de triagem
typedef struct {
    struct tm data; 
    char nome[100];
    int idade;
    float peso;
    float altura;
    float imc;
    int resultadoTriagem;
    char resultado[30];
} Atendimento;

//variáveis globais, ou seja, todo o módulo ou método tem acesso a essas varia'veis
int opcao;
int TAM;
Atendimento *vetor;
char letra;
int i;
int iAux;
int valor; 

//lista de protótipos, ou seja os métodos implementados ao londo do código
int descobrirQuantosAtendimentos();
void trazerDadosArquivoParaVetor();
void menu();
void paraMaiusculo(char nome[]);
void cadastrar();
void listar();
void pesquisar();
void atualizarArquivo();
void trazerDadosArquivoParaVetor();

int descobrirQuantosAtendimentos() {
    int qtdAtendimentos = 0;
    char linha[100];
    
    //abrir o arquivo
    FILE *procuradorArquivo = fopen("covid.dat", "r");
    
    if (!procuradorArquivo) return 0;

    //percorrer o arquivo contando as linhas, logo os atendimentos
    while (fgets(linha,100,procuradorArquivo)) {
        qtdAtendimentos++;
    }

    //fechar o arquivo
    fclose(procuradorArquivo);
    
    return qtdAtendimentos;
}

void menu() {
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
}

void paraMaiusculo(char nome[]) {
    int i;
    for (i = 0; i < strlen(nome); i++) {
        nome[i] = toupper(nome[i]);
    }
}

void cadastrar() {
    system("clear");//para o windows use system("cls");
    printf("CADASTRO DE ATENDIMENTO\n");
    //método cadastrar atendimento
    if (i < TAM){
        //método que recebe os dados do atendimento
        time_t t = time(NULL);
        vetor[i].data = *localtime(&t);
        
        printf("Nome paciente......: ");
        scanf("%s", vetor[i].nome);
        fflush(stdin);

        paraMaiusculo(vetor[i].nome);

        printf("Idade paciente.....: ");
        scanf("%d", &vetor[i].idade);
        fflush(stdin);
        printf("Peso paciente..(kg): ");
        scanf("%f", &vetor[i].peso);
        fflush(stdin);
        printf("Altura paciente.(m): ");
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
            strcpy(vetor[i].resultado, "Baixo");
        } else if (vetor[i].resultadoTriagem < 20) {
            strcpy(vetor[i].resultado, "Médio");
        } else {
            strcpy(vetor[i].resultado, "Alto");
        }
        //poderíamos mostrar ao digitador...
        printf("Seu resultado é: %d com %s\n", vetor[i].resultadoTriagem, vetor[i].resultado);

        i++;
    } else {
        printf("Lotou a estrutura de dados para atendimentos......\n");
    }
}

void listar() {
    system("clear");//para o windows use system("cls");
    printf("LISTAGEM DE ATENDIMENTOS\n");
    //método listar atendimentos
    if (i == 0) {
        printf("Estrutura vazia...\n");
    } else {
        for (iAux = 0; iAux < i; iAux++) {
            printf("Data atendimento: %02d/%02d/%d. Hora: %02d:%02d\n", vetor[iAux].data.tm_mday, vetor[iAux].data.tm_mon + 1, vetor[iAux].data.tm_year + 1900,
                                                                    vetor[iAux].data.tm_hour,  vetor[iAux].data.tm_min);
            printf("Nome............: %s\n", vetor[iAux].nome);
            printf("Idade...........: %d\n", vetor[iAux].idade);
            printf("Peso kg.........: %.1f\n", vetor[iAux].peso);
            printf("Altura m........: %.1f\n", vetor[iAux].altura);
            printf("IMC.............: %.1f\n", vetor[iAux].imc);
            printf("Resultado: %d com %s\n", vetor[iAux].resultadoTriagem, vetor[iAux].resultado);
            printf("---------------------------\n");
        }
    }
}

void gerarBackup() {
    FILE *arquivoOrigem = fopen("covid.dat","r");
    FILE *arquivoDestino = fopen("covid.bak", "w");
    char linha[200];

    while (fgets(linha,200,arquivoOrigem)) {
        fprintf(arquivoDestino,"%s",linha);
        fflush(arquivoDestino);
    }
    fclose(arquivoOrigem);
    fclose(arquivoDestino);
}

void atualizarArquivo() {
    gerarBackup();

    FILE *procuradorArquivoSaida = fopen("covid.dat", "w"); //do zero, se existe, é recriado de novo

    if (i == 0) {
        printf("Problemas em gravar o arquivo, pois a estrutura está vazia...\n");
    } else {
        for (iAux = 0; iAux < i; iAux++) {
            fprintf(procuradorArquivoSaida,"%02d\t%02d\t%d\t", vetor[iAux].data.tm_mday, vetor[iAux].data.tm_mon + 1, vetor[iAux].data.tm_year + 1900);
            fprintf(procuradorArquivoSaida,"%02d\t%02d\t",vetor[iAux].data.tm_hour,  vetor[iAux].data.tm_min);                              
            fprintf(procuradorArquivoSaida,"%s\t", vetor[iAux].nome);
            fprintf(procuradorArquivoSaida,"%d\t", vetor[iAux].idade);
            fprintf(procuradorArquivoSaida,"%.1f\t", vetor[iAux].peso);
            fprintf(procuradorArquivoSaida,"%.1f\t", vetor[iAux].altura);
            fprintf(procuradorArquivoSaida,"%.1f\t", vetor[iAux].imc);
            fprintf(procuradorArquivoSaida,"%d\t%s\n", vetor[iAux].resultadoTriagem, vetor[iAux].resultado);
            fflush(procuradorArquivoSaida);
        }
    }
    fclose(procuradorArquivoSaida);
}

void pesquisar() {
    system("clear");//para o windows use system("cls");
    printf("PESQUISA POR ATENDIMENTO\n");
    //método pesquisar por atendimento
        if (i == 0) {
        printf("Estrutura vazia...\n");
    } else {
        char nome[100];
        int encontrou = 0;
        int opcao;
        printf("Digite nome paciente a pesquisar: ");
        scanf("%s", nome);
        fflush(stdin);
        for (iAux = 0; iAux < i; iAux++) {
            if (strcasecmp(nome, vetor[iAux].nome) == 0) {
                encontrou = 1;
                printf("Data atendimento: %02d/%02d/%d. Hora: %02d:%02d\n", vetor[iAux].data.tm_mday, vetor[iAux].data.tm_mon + 1, vetor[iAux].data.tm_year + 1900,
                                                                            vetor[iAux].data.tm_hour,  vetor[iAux].data.tm_min);
                printf("Nome............: %s\n", vetor[iAux].nome);
                printf("Idade...........: %d\n", vetor[iAux].idade);
                printf("Peso kg.........: %.1f\n", vetor[iAux].peso);
                printf("Altura m........: %.1f\n", vetor[iAux].altura);
                printf("IMC.............: %.1f\n", vetor[iAux].imc);
                printf("Resultado: %d com Risco %s\n", vetor[iAux].resultadoTriagem, vetor[iAux].resultado);
                printf("---------------------------\n");

                printf("Deseja editar? [1-Sim; 0-Não]: ");
                scanf("%d", &opcao);
                fflush(stdin);
                if (opcao == 1) {
                    //vamos editar
                    printf("Novo valor para altura: ");
                    scanf("%f",&vetor[iAux].altura);
                    printf("Novo valor para peso: ");
                    scanf("%f",&vetor[iAux].peso);
                    vetor[iAux].imc = vetor[iAux].peso / (vetor[iAux].altura * vetor[iAux].altura);
                }
            }
        }
        if (!encontrou) {
            printf("Atendimento não localizado na base....\n");
        } else atualizarArquivo();
    }
}

void trazerDadosArquivoParaVetor(){
    FILE *procuradorArquivo = fopen("covid.dat","r");
    if (!procuradorArquivo) return;

    do {
        fscanf(procuradorArquivo,"%d %d %d %d %d %s %d %f %f %f %d %s", &vetor[i].data.tm_mday,
            &vetor[i].data.tm_mon, &vetor[i].data.tm_year, &vetor[i].data.tm_hour, &vetor[i].data.tm_min,
            vetor[i].nome, &vetor[i].idade, &vetor[i].peso, &vetor[i].altura, &vetor[i].imc, 
            &vetor[i].resultadoTriagem, vetor[i].resultado);
        
        vetor[i].data.tm_mon -= 1; //vetor[i].data.tm_mon = vetor[i].data.tm_mon - 1;
        vetor[i].data.tm_year -= 1900;

        if (feof(procuradorArquivo)) break;
        
        i++;
    } while (1);
    fclose(procuradorArquivo);
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    
    i = 0;

    TAM = descobrirQuantosAtendimentos() + 10;
    vetor = malloc(sizeof(Atendimento) * TAM);
    trazerDadosArquivoParaVetor();
    

    do {
        menu();
        switch (opcao) {
            case 1 :cadastrar();
                    atualizarArquivo();
                    break;
            case 2 :listar();
                    break;
            case 3 :pesquisar();
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

    return 1;//deu tudo certo
}