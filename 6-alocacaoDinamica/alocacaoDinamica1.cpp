// Alocar memória
//     - reservar para ocupar memória
//     - alocação estática -> tempo de programação
//     - alocação dinâmica -> tempo de execução

// Alocar dinamicamente otimiza computacionalmente
// um sistema: cpu, ram, disco, dissipação de calor
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

void inicializar(string *vetor, int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = "algoritmos b";
    }
}


void mostrar(string *vetor, int n) {
    for (int i = 0; i < n; i++) {
        cout << vetor[i] << endl;
    }
}

int main() {
    string *vetor;
    int qtd;
    cout << "Quantos nomes quer guardar? ";
    cin >> qtd;
    //comando C e C++ para alocar dinamicamente
    //malloc ou calloc
    vetor = (string *)malloc(sizeof(string) * qtd);
    inicializar(vetor, qtd);
    mostrar(vetor, qtd);

    //comando C e C++ para liberar dinamicamente
    //free
    free(vetor);



    return 1;
}