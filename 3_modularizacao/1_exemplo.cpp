#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int numero;

    system("cls");     //método sem retorno e com 1 parâmetro

    srand(time(NULL)); //2 métodos:
                       //time(NULL) - método com retorno e com 1 parâmetro - NULL
                       //srand(<valor>) - método sem retorno e com 1 parâmetro - retorno time(NULL)

    numero = rand() % 100;  //método rand() é um método com retorno e sem parâmetro

    //<tipo> variavel = metodo(<par1>, <par2>); // método com retorno e 2 parâmetros

    //while (metodo(<par>)) { //método com retorno e 1 parâmetro
    //}

    //if (metodo(<par1>,<par2>) == <valor>) { //método com retorno e 2 parâmetros
    //}

    //<tipo> variavel = metodo1(metodo2(<par>)); // método1 é com retorno, levando valor para variavel
                                                 //método2 é com retorno, levando um valor como parâmetro do
                                                 //método1





    return 1;
}