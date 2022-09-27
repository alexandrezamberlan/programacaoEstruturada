#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *procuradorArquivo;
    char nomeArquivo[200];
    char frase[100];

    //pedir o nome e caminho do arquivo
    printf("Informe caminho e nome do arquivo para gravar conteúdo: ");
    scanf("%s", nomeArquivo);

    //abrir o arquivo
    procuradorArquivo = fopen(nomeArquivo, "a"); //abri para appendar - A de append
    
    
    do {
        fflush(stdin);
        printf("Digite algo: ");
        gets(frase);
        if (strcmp(frase,"sair") == 0) break;
        
        fprintf(procuradorArquivo, "\n%s", frase);
        fflush(procuradorArquivo); //grava literalmente no arquivo.
    } while (1);

    //fechar o arquivo
    fclose(procuradorArquivo);

    return 1;
}