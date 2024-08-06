/*
Fazer um programa em C ou C++ que popule e mostre um vetor com números inteiros e aleatórios. A quantidade de números deve ser igual ao tamanho do vetor inteiro definido. Em seguida, o programa deve mostrar todos os números que aparecem mais de 2 vezes no vetor.
*/

#include <iostream>
#include <vector>
#include <cstdlib>  // Para rand() e srand()
#include <ctime>    // Para time()

using namespace std;

int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    int tamanho;
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    // Cria um vetor de inteiros com o tamanho definido
    vector<int> vetor(tamanho);

    // Popula o vetor com números aleatórios entre 0 e 99
    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = rand() % 100;  // Números aleatórios entre 0 e 99
    }

    // Exibe os números no vetor
    cout << "Numeros no vetor: ";
    for (int i = 0; i < tamanho; ++i) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    int contaOcorrencia;
    int numeroAnalisado;
    vector<int> vetorRepetidos(tamanho);
    int iRepetidos = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] != -27) {
            numeroAnalisado = vetor[i];
            contaOcorrencia = 0;
            for (int j = 0; j < tamanho; j++) {
                if (numeroAnalisado == vetor[j]) {
                    contaOcorrencia++;
                    if (contaOcorrencia > 1) {
                        vetor[j] = -27;
                    }
                }
            }
            if (contaOcorrencia > 1){
                vetorRepetidos[iRepetidos] = numeroAnalisado;
                iRepetidos++;
            }
        }
    }

    //exibir os números que repetem mais de uma vez
    cout << "Numeros repetidos ....";
    for (int i = 0; i < iRepetidos; i++) {
        cout << vetorRepetidos[i];
    }
    cout << endl;
    return 0;
}
