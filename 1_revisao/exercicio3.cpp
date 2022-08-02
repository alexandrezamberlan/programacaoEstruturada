#include <iostream>
#include <string>
#define N 5  

using namespace std;
//3) Fazer um programa em C++ que receba 5 nomes de pessoas. Entretanto, antes dos nomes serem inseridos no vetor, os nomes devem ser transformados em maiúsculos e verificados se já foram inseridos anteriormente na estrutura.
int main() {
  //declarando a estrutura
  string vetor[N];
  string nome;
  int qtdNomes = 0;
  bool jaCadastrado;
  int i = 0;
 
  do {
    cout << "Digite nome: ";
    cin >> nome;

    //rotina que transforma o nome para maiusculo

    //rotina que verifica se o nome ja está inserido
    jaCadastrado = false;
    for (int j = 0; j < qtdNomes; j++) {
      if (nome == vetor[j]) {
        cout << "Nome ja cadastrado\n";
        jaCadastrado = true;
        break;
      }
    }
    
    if (!jaCadastrado) {      
      vetor[i] = nome;
      qtdNomes++;
      i++;
    } 
  } while (i < N);

  //exibir os nomes cadastrados
  cout << "Nomes presentes no vetor\n";
  for (int i = 0; i < qtdNomes; i++) {
    cout << vetor[i] << endl;
  }
  
  return 1;
}
