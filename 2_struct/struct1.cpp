#include <iostream>
using namespace std;

typedef struct {
  int codigo;
  float salarioFixo;
  float totalVendas;
  float comissao;
  float salarioTotal;
} Vendedor; //tipo artificial criado pelo programador

int main() {
  Vendedor umVendedor; 

  cout << "Digite seu código: ";
  cin >> umVendedor.codigo;

  cout << "Salário fixo: ";
  cin >> umVendedor.salarioFixo;

  cout << "Total de vendas: ";
  cin >> umVendedor.totalVendas;

  if (umVendedor.totalVendas <= 1000) {
    //totalVendas - 100
    //comissao    - 3
    umVendedor.comissao = (umVendedor.totalVendas * 3 / 100) + umVendedor.totalVendas;
  } else if (umVendedor.totalVendas <= 2000) {
    //totalVendas - 100
    //comissao    - 5
    umVendedor.comissao = (umVendedor.totalVendas * 5 / 100) + umVendedor.totalVendas;
  } else {
    //totalVendas - 100
    //comissao    - 10
    umVendedor.comissao = (umVendedor.totalVendas * 10 / 100) + umVendedor.totalVendas;
  }

  umVendedor.salarioTotal = umVendedor.salarioFixo + umVendedor.comissao;
  cout << "Seu salário total é: " << umVendedor.salarioTotal << endl;

  return 0;
}
