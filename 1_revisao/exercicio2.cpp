#include <iostream>
#include <ctime>
#include <cstdlib>
#define N 10  

using namespace std;
// 2) Fazer um programa em C++, que recebe o vetor populado e exibido no código anterior, fazendo a operação de ordenação no vetor. Ao final, mostrar o vetor ordenado.

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

  //ordenando o vetor pelo método Bubble Sort (bolha)
  bool houveTroca;
  int temp;
  do {
    houveTroca = false;
    for (int i = 0; i < N - 1; i++) {
      if (vetor[i] > vetor[i+1]) {
        temp = vetor[i];
        vetor[i] = vetor[i+1];
        vetor[i+1] = temp;
        houveTroca = true;
      }
    }
  } while (houveTroca);

  //exibindo os valores do vetor
  cout << "Valores ordenados no vetor\n";
  for (int i = 0; i < N; i++) {
    cout << vetor[i] << "\t";
  }
  cout << endl;
  
  return 1;
}
