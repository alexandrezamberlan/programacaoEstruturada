#include <stdio.h>
#include <stdlib.h>

//programa que vai abrir um arquivo de texto (plain text) e mostrar seu conteúdo na tela do computador

int main() {
    FILE *procuradorArquivo;
    char nomeArquivo[200];
    char linha[100];

    //pedir o nome e caminho do arquivo
    printf("Informe caminho e nome do arquivo texto que quer exibir na tela: ");
    scanf("%s", nomeArquivo);

    //abrir o arquivo
    procuradorArquivo = fopen(nomeArquivo, "r"); //abri para ler - R de read
    
    //caso exista, percorre-lo e exibir linha a linha na tela
    if (!procuradorArquivo) {
        printf("Arquivo não localizado..... sistema encerrado!\n");
        exit(0);
    }

    while (fgets(linha,100,procuradorArquivo)) {
        printf("%s", linha);
    }
    printf("\n");

    //fechar o arquivo
    fclose(procuradorArquivo);

    return 1;
}