#include <iostream>
#include <ctime>
#include <cstdlib>
#define N 10  

using namespace std;
// 1) Fazer um programa em C++, populando um vetor (tamanho N) com números aleatórios de 0 a 100. Na sequência, o vetor deve ser exibido, bem como o maior e o menor valor inseridos.

int main() {
  //declarando a estrutura
  int vetor[N];

  //populando a estrutura
  srand(time(NULL));
  for (int i = 0; i < N; i++) {
    vetor[i] = rand() % 101;
  }

  //exibindo os valores do vetor
  cout << "Valores gerados para o vetor\n";
  for (int i = 0; i < N; i++) {
    cout << vetor[i] << "\t";
  }
  cout << endl;

  //descobrindo o menor valor
  int menor = vetor[0];
  int posicaoMenor = 0;
  for (int i = 1; i < N; i++) {
    if (vetor[i] < menor) {
      menor = vetor[i];
      posicaoMenor = i;
    }
  }
  cout << "O menor valor encontrado na estrutura eh: " << menor << " localizado na posicao " << posicaoMenor << endl;

  //descobrindo o maior valor
  int maior = vetor[0];
  int posicaoMaior = 0;
  for (int i = 1; i < N; i++) {
    if (vetor[i] > maior) {
      maior = vetor[i];
      posicaoMaior = i;
    }
  }
  cout << "O maior valor encontrado na estrutura eh: " << menor << " localizado na posicao " << posicaoMaior << endl;

  return 1;
}
