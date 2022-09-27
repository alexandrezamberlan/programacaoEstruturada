#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//programa que vai abrir um arquivo de texto (plain text) e mostrar seu conteúdo na tela do computador

typedef struct {
    int x;
    int y;
    char time[100];
} Coordenada;

int main() {
    Coordenada vetorVermelho[1000];
    Coordenada vetorAzul[1000];

    FILE *procuradorArquivo;
    char nomeArquivo[200];
    int x, y;
    char time[100];

    //pedir o nome e caminho do arquivo
    printf("Informe caminho e nome do arquivo texto que extrair nome, idade e sexo: ");
    scanf("%s", nomeArquivo);

    //abrir o arquivo
    procuradorArquivo = fopen(nomeArquivo, "r"); //abri para ler - R de read
    
    //caso exista, percorre-lo, extrair cada coluna na variável respectiva e mostrar somente nome
    if (!procuradorArquivo) {
        printf("Arquivo não localizado..... sistema encerrado!\n");
        exit(0);
    }

    int iAzul = 0;
    int iVermelho = 0;
    while (!feof(procuradorArquivo)) { //enquanto o procuradoArquivo não estiver no final, faça
        fscanf(procuradorArquivo, "%d %d %s", &x, &y, time);
        if (strcmp(time,"azul")) {
            vetorAzul[iAzul].x = x;
            vetorAzul[iAzul].y = y;
            strcpy(vetorAzul[iAzul].time, time);
            iAzul++;
        } else {
            vetorVermelho[iVermelho].x = x;
            vetorVermelho[iVermelho].y = y;
            strcpy(vetorVermelho[iVermelho].time, time);
            iVermelho++;
        }
    }

    int iAux;
    printf("Time azul....\n");
    for (iAux = 0; iAux < iAzul; iAux++) {
        printf("(%d,%d) - %s\n", vetorAzul[iAux].x, vetorAzul[iAux].y, vetorAzul[iAux].time);
    }

    printf("Time vermelho....\n");
    for (iAux = 0; iAux < iVermelho; iAux++) {
        printf("(%d,%d) - %s\n", vetorVermelho[iAux].x, vetorVermelho[iAux].y, vetorVermelho[iAux].time);
    }

    //fechar o arquivo
    fclose(procuradorArquivo);

    return 1;
}