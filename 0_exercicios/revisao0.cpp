#include <iostream>
#include <string>

#define TAMANHO 3 //constante 

using namespace std;

/*
Fazer um programa que receba nomes em um vetor de strings, controlando
os duplicados
*/
int main() {
    system("cls");
    cout << "Primeira revisao\n";
    string vetorNomes[TAMANHO];
    string nome;
    int i = -1; //variavel que mostra onde esta o ultimo nome do vetor
    bool encontrado;
    while (i < (TAMANHO - 1)) {
        cout << "Digite um nome: ";
        //cin >> nome;
        getline(cin,nome);

        //conferir se o nome digitado esta ou nao no vetor
        encontrado = false;
        for (int p = 0; p <= i; p++) {
            if (nome == vetorNomes[p]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            i++;
            vetorNomes[i] = nome;
        } else {
            cout << "Nome jah digitado\n";
        }
    }
    cout << "Lista de nomes!\n";
    for (int i = 0; i < TAMANHO; i++) {
        cout << vetorNomes[i] << endl;
    }

    return 1;
}