/*
Dado o código abaixo:
1) qual a soma dos elementos da matriz gerada?
2) qual a média dos elementos da matriz gerada?
3) qual o maior elemento da matriz gerada?
4) qual a soma dos elementos da diagonal principal da matriz gerada?
5) qual a soma dos elementos da primeira linha da matriz gerada?
6) qual a soma dos elementos da última coluna da matriz gerada?
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define TAMANHO 5

int main() {
    system("cls");
    int matriz[TAMANHO][TAMANHO];

    srand(time(NULL));
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            matriz[i][j] = rand() % 10;
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 1;
}