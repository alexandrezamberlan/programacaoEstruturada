#include <iostream>
#include <cstdlib> //para sortear numeros
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));
    cout << "Numero sorteado: " << (rand() % 21) - 10 << endl;


    cout << "Vamos popular um vetor de 10 posicoes com numeros aleatorios de 0 a 99 \n";
    int vetor[10];

    for (int i = 0; i < 10; i++) {
        vetor[i] = rand() % 100;
    }

    for (int i = 0; i < 10; i++) {
        cout << vetor[i] << "\t";
    }



    return 1;
}