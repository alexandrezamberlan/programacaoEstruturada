/**
 * Dando continuidade ao programa anterior, fazer uma refatoração que analise os números do vetor. Os números impares devem ser copiados para o vetorImpar e os números pares devem ser copiados para o vetorPar. O tamanho dos vetores devem ser iguais ao do vetor original.
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
    cout << "Números no vetor: ";
    for (int i = 0; i < tamanho; ++i) {
        cout << vetor[i] << " ";
    }

    cout << endl;

    vector<int> vetorPar(tamanho); //int vetorPar[tamanho]
    vector<int> vetorImpar(tamanho); //int vetorImpar[tamanho]
    int iPar = 0;
    int iImpar = 0;

    // Separa os pares dos impares
    for (int i = 0; i < tamanho; ++i) {
        if (vetor[i] % 2 == 0) {
            vetorPar[iPar] = vetor[i];
            iPar++;
        } else {
            vetorImpar[iImpar] = vetor[i];
            iImpar++;
        }
    }

    // Exibe os números pares
    cout << "Numeros pares... ";
    for (int i = 0; i < iPar; ++i) {
        cout << vetorPar[i] << " ";
    }
    
    cout << endl;

    // Exibe os números impares
    cout << "Numeros impares... ";
    for (int i = 0; i < iImpar; ++i) {
        cout << vetorImpar[i] << " ";
    }

    cout << endl;

    return 0;
}
