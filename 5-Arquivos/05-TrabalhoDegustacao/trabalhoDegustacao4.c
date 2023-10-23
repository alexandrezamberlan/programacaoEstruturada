/**
 * Construir um Sistema para gerenciar degustações de cervejas artesanais. 
 * É preciso no mínimo armazenar dados fabricante, estilo da cerveja, nota da degustação e data da degustação.
 * O sistema deve conter um Menu: (cadastrar degustação, listar degustações, ranquear degustações 
 * da nota mais alta para a mais baixa, listar degustações por estilos).
 * 
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define TAM 1000

typedef struct{
    char nomeFabricante[100];
    char tipoCerveja[100];
    char nomeDegustador[100];
    int notaDegustacao;
    struct tm dataHoraDegustacao;
} Degustacao;

void paraMaiusculo(char *n) {
    int i;
    int tamanho = strlen(n);
    for (i = 0; i < tamanho; i++) {
        n[i] = toupper(n[i]);
    }
}

void gerarDegustacao(Degustacao lista[], int *i) {
    if (*i < TAM) {
        //método que recebe os dados da degustacao
        time_t t = time(NULL);
        lista[*i].dataHoraDegustacao = *localtime(&t);

        printf("Fabricante: ");
        gets(lista[*i].nomeFabricante);
        paraMaiusculo(lista[*i].nomeFabricante);
        fflush(stdin);

        printf("Estilo da cerveja: ");
        gets(lista[*i].tipoCerveja);
        paraMaiusculo(lista[*i].tipoCerveja);
        fflush(stdin);

        printf("Degustador: ");
        gets(lista[*i].nomeDegustador);
        paraMaiusculo(lista[*i].nomeDegustador);
        fflush(stdin);

        do {
            printf("Nota para degustação (0-5): ");
            scanf("%d", &lista[*i].notaDegustacao);
            fflush(stdin);
            if (lista[*i].notaDegustacao >= 0 && lista[*i].notaDegustacao <= 5) {
                break;
            } else {
                printf("Fique atento a nota (0 a 5)\n");
            }
        } while(1);

        *i = *i + 1; 
    } else {
        printf("Estrutura lotada para degustações\n");
    }
}

void listarDegustacoes(Degustacao lista[], int *i) {
    if (*i == 0) {
        printf("Estrutura vazia de degustações!\n");
    } else {
        int iAux;
        for (iAux = 0; iAux < *i; iAux++) {
            printf("Data degustação: %02d/%02d/%d. Hora: %02d:%02d\n", lista[iAux].dataHoraDegustacao.tm_mday, lista[iAux].dataHoraDegustacao.tm_mon + 1, lista[iAux].dataHoraDegustacao.tm_year + 1900,
                                                                    lista[iAux].dataHoraDegustacao.tm_hour,  lista[iAux].dataHoraDegustacao.tm_min);
            printf("Tipo cerveja   : %s\n", lista[iAux].tipoCerveja);
            printf("Brewer         : %s\n", lista[iAux].nomeFabricante);
            printf("Degustador     : %s\n", lista[iAux].nomeDegustador);
            printf("Avaliação      : %d\n", lista[iAux].notaDegustacao);
            printf("----------------------------------\n");
        }
    }
}

void rankearDegustacoes(Degustacao lista[], int *i) {
    //chamar o método de ordenacao bolha - bubble sort
    int iAux, houveTroca;
    Degustacao tmp;

    do {
        houveTroca = 0; //inicio o processo assumindo que nao houve troca
        for (iAux = 0; iAux < *i - 1; iAux++) {
            if (lista[iAux].notaDegustacao < lista[iAux + 1].notaDegustacao) {
                houveTroca = 1;
                tmp = lista[iAux];
                lista[iAux] = lista[iAux + 1];
                lista[iAux + 1] = tmp;
            }
        }
    } while (houveTroca);
    listarDegustacoes(lista,i);
}

//& -> *
void menu(Degustacao lista[], int *i) {
    int opcao;
    char letra;
    do {
        system("clear");//para o windows use system("cls");
        printf("Menu para degustação Cervejas Artesanais\n");
        printf("1 - Gerar degustação\n");
        printf("2 - Listar degustações\n");
        printf("3 - Listar degustações por estilos\n");
        printf("4 - Rankear cervejas por estilo\n");
        printf("5 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao)
        {
        case 1:
            printf("GERAR DEGUSTAÇÃO\n\n");
            gerarDegustacao(lista, i);
            break;
        case 2:
            printf("LISTAR TODAS AS DEGUSTAÇÕES\n\n");
            listarDegustacoes(lista, i);
            break;
        case 3:
            printf("LISTAR DEGUSTAÇÕES POR ESTILO\n\n");
            //chamada do metodo
            break;
        case 4:
            printf("RANKEAR AS CERVEJAS POR ESTILO\n\n");
            rankearDegustacoes(lista, i);
            break;
        case 5:
            printf("Obrigado por usar nosso sistema\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
        printf("Tecle Enter para continuar!!!");
        letra = getchar();//system("pause");
        fflush(stdin);
    } while (opcao != 5);
}

int main() {
    Degustacao lista[TAM];
    int i = 0;

    //1o parametro é por referência, pois é um vetor
    //2o parametro é por referência EXPLICITA, pois há um &
    menu(lista, &i);

    return 1;
}
