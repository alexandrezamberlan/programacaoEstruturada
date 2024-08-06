/* Fazer um programa em C ou C++ que popule e mostre um vetor com números inteiros e aleatórios. A quantidade de números deve ser igual ao tamanho do vetor inteiro definido. Em seguida, o programa deve receber um número inteiro qualquer e verificar quantas vezes ele aparece no vetor.
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

    int valorPesquisa;
    cout << "Digite um valor para pesquisar: ";
    cin >> valorPesquisa;

    //pesquisar o valor no vetor e contar qtas vezes ele aparece
    int contaOcorrencia = 0;
    for (int i = 0; i < tamanho; i++) {
        if (valorPesquisa == vetor[i]) {
            contaOcorrencia++;
        }
    }

    cout << valorPesquisa << " aparece no vetor " << contaOcorrencia << " vezes\n";

    return 0;
}
