#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//programa que vai abrir um arquivo de texto (plain text) e mostrar seu conteúdo na tela do computador

typedef struct {
    char nome[100];
    int idade;
    char sexo[100];
} Pessoa;

int main() {
    Pessoa vetor[1000];

    FILE *procuradorArquivo;
    char nomeArquivo[200];
    char nome[100], sexo[100];
    int idade;

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

    int i = 0;
    while (!feof(procuradorArquivo)) { //enquanto o procuradoArquivo não estiver no final, faça
        fscanf(procuradorArquivo, "%s %d %s", nome, &idade, sexo);
        strcpy(vetor[i].nome, nome);
        vetor[i].idade = idade;
        strcpy(vetor[i].sexo, sexo);
        i++;
    }

    int iAux;
    for (iAux = 0; iAux < i; iAux++) {
        printf("Nome: %s. Idade: %d\n", vetor[iAux].nome, vetor[iAux].idade);
    }

    //fechar o arquivo
    fclose(procuradorArquivo);

    return 1;
}