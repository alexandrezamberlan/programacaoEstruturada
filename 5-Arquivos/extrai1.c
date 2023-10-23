#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
/*
código que recebe uma frase e retorna quantas palavras há nela
*/

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

int main() {
    char frase[100];

    setlocale(LC_ALL,"Portuguese");
    
    printf("Digite uma frase: ");
    gets(frase);

    printf("Na frase há %d palavras\n", contarPalavras1(frase));

    mostrarPalavras2(frase);

    return 1;
}