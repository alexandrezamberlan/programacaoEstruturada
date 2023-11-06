#include <iostream>
#include <string>
#include <time.h>
#define TAM 50
using namespace std;

#include "./model/struct.h"

#include "./model/persistencia.h"

#include "./view/menu.h"

int main() {
    Pessoa vetor[TAM];
    int totalInscritos = conectarBase(vetor,TAM);
    menu(vetor, TAM, totalInscritos);   
    return 1;
}