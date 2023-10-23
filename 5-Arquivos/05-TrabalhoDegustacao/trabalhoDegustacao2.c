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

//menu
    //Gerar degustação
    //Listar degustações geral e por estilo
    //Rankear degustações por tipo (algoritmo de ordenação)

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
            //chamada do metodo
            // gerarDegustacao(lista,i);
            break;
        case 2:
            printf("LISTAR TODAS AS DEGUSTAÇÕES\n\n");
            //chamada do metodo
            break;
        case 3:
            printf("LISTAR DEGUSTAÇÕES POR ESTILO\n\n");
            //chamada do metodo
            break;
        case 4:
            printf("RANKEAR AS CERVEJAS POR ESTILO\n\n");
            //chamada do metodo
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

/**
 *  time_t t = time(NULL);
  struct tm dataHora = *localtime(&t);
  printf("Agora: %02d/%02d/%d  %02d:%02d:%02d\n", dataHora.tm_mday, dataHora.tm_mon + 1, dataHora.tm_year + 1900, dataHora.tm_hour, dataHora.tm_min, dataHora.tm_sec);
 */ 