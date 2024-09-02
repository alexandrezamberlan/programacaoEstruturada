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
}