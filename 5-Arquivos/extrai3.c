#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[100];
    int idade;
    char categoria[100];
} Pessoa;


void popularVetor(char *linha, Pessoa *vetorPessoas, int *p) {
    //na linha deve ter: matricula, nome, idade, categoria
    char palavra[100];
    int i, j;
    int contaArroba = 0;

    for (i = 0, j = 0; i < strlen(linha)+1; i++) {
        if (linha[i] != '@' && linha[i] != '\0' && linha[i] != '\n' ) {
            palavra[j] = linha[i];
            j++;
        } else {
            contaArroba++;
            palavra[j] = '\0';
            if (palavra[0] != '\0') {
                switch (contaArroba) {
                    case 1 : //matricula
                            vetorPessoas[*p].matricula = atoi(palavra);
                            break;
                    case 2 : //nome
                            strcpy(vetorPessoas[*p].nome, palavra);
                            break;
                    case 3 : //idade
                            vetorPessoas[*p].idade = atoi(palavra);
                            break;
                    case 4 : //categoria
                            strcpy(vetorPessoas[*p].categoria,palavra);
                            break;            
                }
            }
            j = 0;
            strcpy(palavra, "");
        }
    }
}

void abrirArquivoPopularVetor(Pessoa *vetorPessoas, int *i) {
    FILE *procuradorArquivo;
    procuradorArquivo = fopen("dados.dat", "r");

    if (!procuradorArquivo) {
        printf("Base de dados corrompida....\n");
        exit(0);
    }

    char linha[100];
    while (fgets(linha,100,procuradorArquivo)) {
        popularVetor(linha, vetorPessoas, i); //note que o i é um ponteiro, logo ele é passado como referência
        *i = *i + 1;
    }
    fclose(procuradorArquivo);
}

void exibirVetor(Pessoa *vetorPessoas, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("----------------------------------------\n");
        printf("Matricula: %d\n", vetorPessoas[i].matricula);
        printf("Nome     : %s\n", vetorPessoas[i].nome);
        printf("Idade    : %d\n", vetorPessoas[i].idade);
        printf("Categoria: %s\n", vetorPessoas[i].categoria);
        printf("----------------------------------------\n");
    }
}

int main() {
    Pessoa vetorPessoas[100];
    int i = 0;

    abrirArquivoPopularVetor(vetorPessoas, &i);
    exibirVetor(vetorPessoas, i); //variável

    return 1;
}