#include <iostream>
#define TAM 5
using namespace std;

typedef struct {
  int codigo;
  float salarioFixo;
  float totalVendas;
  float comissao;
  float salarioTotal;
} Vendedor; //tipo artificial criado pelo programador

int main() {
  Vendedor vetor[TAM];   

  for (int i = 0; i < TAM; i++) {
    cout << "Digite código do " << (i+1) << "º vendedor: ";
    cin >> vetor[i].codigo;

    cout << "Salário fixo: ";
    cin >> vetor[i].salarioFixo;

    cout << "Total de vendas: ";
    cin >> vetor[i].totalVendas;

    if (vetor[i].totalVendas <= 1000) {
        //totalVendas - 100
        //comissao    - 3
        vetor[i].comissao = (vetor[i].totalVendas * 3 / 100) + vetor[i].totalVendas;
    } else if (vetor[i].totalVendas <= 2000) {
        //totalVendas - 100
        //comissao    - 5
        vetor[i].comissao = (vetor[i].totalVendas * 5 / 100) + vetor[i].totalVendas;
    } else {
        //totalVendas - 100
        //comissao    - 10
        vetor[i].comissao = (vetor[i].totalVendas * 10 / 100) + vetor[i].totalVendas;
    }

    vetor[i].salarioTotal = vetor[i].salarioFixo + vetor[i].comissao;
    cout << "Seu salário total é: " << vetor[i].salarioTotal << endl;
  }

  cout << "Exibindo vendedores: \n";
  for (int i = 0; i < TAM; i++) {
    cout << "Código do " << (i+1) << "º vendedor: " << vetor[i].codigo;
    cout << "Salário fixo: " << vetor[i].salarioFixo;
    cout << "Total de vendas: " << vetor[i].totalVendas;
    cout << "Salário total: " << vetor[i].salarioTotal << endl;
    cout << "_____________________________\n";
  }

  return 0;
}
