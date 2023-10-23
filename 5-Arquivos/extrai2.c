#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

int contarPalavras1(char *frase) {
    int qtdEspacosEmBranco = 0;
    int i;
    for (i = 0; i < strlen(frase); i++) {
       
        if (frase[i] == '@') {
            qtdEspacosEmBranco++;
        }
    }
    return ++qtdEspacosEmBranco;
}

void mostrarPalavras(char *frase) {
    char palavra[100];
    int i, j;
    for (i = 0, j = 0; i < strlen(frase)+1; i++) {
        if (frase[i] != ' ' && frase[i] != '\0') {
            palavra[j] = frase[i];
            j++;
        } else {
            palavra[j] = '\0';
            if (palavra[0] != '\0') {
                printf("%s\n", palavra);
            }
            j = 0;
            strcpy(palavra, "");
        }
    }
}

void mostrarPalavras2(char *frase) {
    char palavra[100];
    int i, j;
    for (i = 0, j = 0; i < strlen(frase)+1; i++) {
        if (frase[i] != '@' && frase[i] != '\0') {
            palavra[j] = frase[i];
            j++;
        } else {
            palavra[j] = '\0';
            if (palavra[0] != '\0') {
                printf("%s\n", palavra);
            }
            j = 0;
            strcpy(palavra, "");
        }
    }
}

void abrirArquivo() {
    FILE *procuradorArquivo;
    procuradorArquivo = fopen("dados.dat", "r");

    if (!procuradorArquivo) {
        printf("Base de dados corrompida....\n");
        exit(0);
    }

    char linha[100];
    while (fgets(linha,100,procuradorArquivo)) {
        mostrarPalavras2(linha);
        printf("-------------------\n\n");
    }
    fclose(procuradorArquivo);
}

int main() {
    
    abrirArquivo();

    return 1;
}