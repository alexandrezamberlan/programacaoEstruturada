#include <iostream>
#include <string>
#include <time.h>
#define TAM 50
using namespace std;

#include "structs.h"

#include "metodos.h"

int main() {
    Participante vetor[TAM];
    int totalInscritos = conectarBase(vetor,TAM);
    menu(vetor, TAM, totalInscritos);   
    return 1;
}