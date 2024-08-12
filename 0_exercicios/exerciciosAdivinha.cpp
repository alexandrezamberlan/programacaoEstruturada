/*
Fazer um programa em C ou C++ que popule e mostre um vetor com números inteiros e aleatórios. A quantidade de números deve ser igual ao tamanho do vetor inteiro definido. Em seguida, o programa deve mostrar todos os números que aparecem mais de 2 vezes no vetor.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
int main() {
    system("cls");
    int tamanho;
    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    // Cria um vetor de inteiros com o tamanho definido
    vector<int> vetor(tamanho);

    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 10;
        cout << vetor[i] << " ";
    }

    int contaOcorrencia;
    int numeroAnalisado;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] != -27) {
            numeroAnalisado = vetor[i];
            contaOcorrencia = 1;
            for (int j = i+1; j < tamanho; j++) {
                if (numeroAnalisado == vetor[j]) {
                    contaOcorrencia++;
                    if (contaOcorrencia > 1) {
                        vetor[j] = -27;
                    }
                }
            }
            if (contaOcorrencia > 1){
                cout << vetor[i] << " aparece " << contaOcorrencia << " vezes\n";
            }
        }
    }

    cout << endl;
    return 1;
}
