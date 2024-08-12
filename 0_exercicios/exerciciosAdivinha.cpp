#include <iostream>
#include <string>
#include <vector>
#define TAMANHO 5
using namespace std;

int main() {
    vector<string> nomes(TAMANHO);

    for (int i = 0; i < TAMANHO; i++) {
        cout << "Digite o nome " << i+1 << ": ";
        cin >> nomes[i];
    }

    bool houveTroca = true;
    while (houveTroca) {
        houveTroca = false;
        for (int i = 0; i < TAMANHO-1; i++) {
            if (nomes[i] > nomes[i+1]) {
                string aux = nomes[i];
                nomes[i] = nomes[i+1];
                nomes[i+1] = aux;
                houveTroca = true;
            }
        }
    }

    cout << nomes[0] << endl;
    cout << nomes[TAMANHO-1] << endl;

    return 1;
}
