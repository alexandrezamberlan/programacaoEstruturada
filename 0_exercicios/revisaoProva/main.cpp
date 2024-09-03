#include <iostream>
#include <vector>
#define TAMANHO 5
using namespace std;

#include "metodos.h"

int main() {
    int vetor1[TAMANHO];
    int vetor2[TAMANHO];

    popularVetor(vetor1, TAMANHO);
    exibirVetor(vetor1, TAMANHO);

    escreverMenor(vetor1, TAMANHO);
    cout << "Funcao: o menor valor eh: " << pegarMenor(vetor1, TAMANHO) << endl;

    escreverSoma(vetor1, TAMANHO);
    cout << "Funcao: a soma dos elementos eh: " << somar(vetor1, TAMANHO) << endl;

    popularVetor(vetor2, TAMANHO);
    substituirPares(vetor2, TAMANHO);
    exibirVetor(vetor2, TAMANHO);

    //Copiando o conteudo do vetor1 para o vetor2
    cout << "Copiando vetor....\n";
    copiarVetor(vetor1,vetor2,TAMANHO);
    cout << "Vetor1\n";
    exibirVetor(vetor2, TAMANHO);
    cout << "Vetor2\n";
    exibirVetor(vetor2, TAMANHO);
}
