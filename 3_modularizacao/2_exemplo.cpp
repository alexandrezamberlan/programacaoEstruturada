#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "metodos.h"

int main() {
    int vetor1[10];
    int vetor2[10];
    int vetor3[10];

    system("cls");

    popularVetor(vetor1, 10);
    exibirVetor(vetor1, 10, "Dados do vetor 1\n");


    popularVetor(vetor2, 10);
    exibirVetor(vetor2, 10, "Dados do vetor 2\n");

    popularVetor(vetor3, 10);
    exibirVetor(vetor3, 10, "Dados do vetor 3\n");
    
    return 1;
}