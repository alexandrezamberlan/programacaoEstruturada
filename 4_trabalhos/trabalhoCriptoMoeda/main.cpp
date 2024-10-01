#include <iostream>
#include <string>

#define TAM 100

using namespace std;

#include "util.h"
#include "metodos.h"

int main() 
{
    string nomeDaBase = "cripto.csv";
    Cripto lista[TAM];
    int totalCadastrados = 0;

    totalCadastrados = conectarComBase(nomeDaBase, lista, TAM);
    menu(lista, totalCadastrados, TAM, nomeDaBase);

    return 1;
}