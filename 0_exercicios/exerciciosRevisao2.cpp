 /** 
 * 1 - Escrever um algoritmo que lê o código de um vendedor de uma empresa, 
 * seu salário fixo e o total de vendas efetuadas por ele. 
 * Cada vendedor recebe um salário fixo, mais uma comissão proporcional 
 * às vendas efetuadas por ele. A comissão é de 3% sobre o total de 
 * vendas até R$1.000,00; 5% de R$1.000,00 à R$2.000,00 e 10% para 
 * vendas acima de R$2.000,00. Escrever o código do vendedor, o total 
 * de suas vendas, seu salário fixo e seu salário total.
 */
 #include <iostream>
using namespace std;

int main() {
  cout << "Exercício 1\n";

  //receber dados de um vendedor
  int codigo;
  float salarioFixo;
  float totalVendas;
  float comissao;
  float salarioTotal;

  cout << "Digite seu código: ";
  cin >> codigo;

  cout << "Salário fixo: ";
  cin >> salarioFixo;

  cout << "Total de vendas: ";
  cin >> totalVendas;

  if (totalVendas <= 1000) {
    //totalVendas - 100
    //comissao    - 3
    comissao = (totalVendas * 3 / 100) + totalVendas;
  } else if (totalVendas <= 2000) {
    //totalVendas - 100
    //comissao    - 5
    comissao = (totalVendas * 5 / 100) + totalVendas;
  } else {
    //totalVendas - 100
    //comissao    - 10
    comissao = (totalVendas * 10 / 100) + totalVendas;
  }

  salarioTotal = salarioFixo + comissao;
  cout << "Seu salário total é: " << salarioTotal << endl;
  
  return 0;
}

 /**
 * 2 - Escrever um algoritmo para ler quatro valores inteiros, calcular a sua média, e 
 * escrever na tela os que são superiores à média.
 */ 

 #include <iostream>

using namespace std;

int main() {
  int valor1, valor2, valor3, valor4;
  int somaValores;
  float media;
  
  cout << "Digite o primeiro valor: ";  
  cin >> valor1;

  cout << "Digite o segundo valor: ";
  cin >> valor2;

  cout << "Digite o terceiro valor: ";
  cin >> valor3;

  cout << "Digite o quarto valor: ";
  cin >> valor4;

  somaValores = valor1 + valor2 + valor3 + valor4;
  media = somaValores / 4;

  cout << "A soma dos valores: " << somaValores << endl;
  cout << "A média dos valores: " << media << "\n";

  return 0;
}



#include <iostream>

using namespace std;

int main() {
  int vetor[4];
  int somaValores = 0;
  float media;
  
  for (int i = 0; i < 4; i++) {
    cout << "Digite o valor " << (i+1) << ": ";
    cin >> vetor[i];
    somaValores = somaValores + vetor[i];
  }
  media = somaValores / 4;
  
   cout << "A soma dos valores: " << somaValores << endl;
  cout << "A média dos valores: " << media << "\n";
  
  return 0;
}
 
 /**
 * 3 - Escreva um algoritmo para calcular o reajuste salarial de uma empresa que possui 1000 
 * funcionários, de acordo com os seguintes critérios:
 *	• os funcionários com salário inferior a 10.000 devem receber 55% de reajuste
 *	• os funcionários com salário entre 10.000 e 25.000 devem receber 30% de reajuste.
 *	• os funcionários com salário acima de 25.000 devem receber 20% de reajuste.
 */ 
 
 /**
 * 4 - Faça um programa que leia uma palavra qualquer e depois mostre apenas as vogais.
 */ 
 
 /*
 * 5 - Faça um algoritmo que possua dois vetores, 
 * um preenchido com valores seqüenciais de 0 a 9 e outro com valores sequenciais de 10 a 19, 
 * e intercale-os num terceiro vetor formando uma nova variável. Mostre o vetor obtido.
 */
 
 /*
 * 6 - Elabore um algoritmo que dados dois vetores inteiros de 20 posições, 
 * efetue as respectivas operações matemáticas indicadas em um terceiro vetor de 20 
 * posições de caracteres. Armazene o resultado de cada operação em outro vetor de 20 inteiros. 
 * Utilize as quatro operações aritméticas (+, -, *, /).
 */
 
 /**
 * 7 - Ler uma matriz de inteiros com ordem 10x10, sem elementos duplicados. 
 * Ler, a seguir, 10 valores e verificar se cada valor lido é um dos elementos da matriz. 
 * Se o valor for encontrado na matriz, exibir o valor encontrado e a posição do elemento 
 * na matriz (por exemplo: “O valor X foi encontrado na posição I,J da matriz”).
 */
 
 /**
 * 8 - Faça um programa que crie uma matriz 4x4, calcule e mostre:
 *	• A soma dos elementos da primeira linha
 *	• O produto dos elementos da primeira coluna
 *	• A soma da diagonal principal
 *	• A soma de todos os elementos da matriz
 */
