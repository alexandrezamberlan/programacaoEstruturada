#include <iostream>
#include <string>

using namespace std;

int main() {
    string nome;

    cout << "Digite seu nome: ";
    cin >> nome; //equivale ao scanf ou gets 

    cout << "Voce digitou: " << nome << endl;
    cout << "O nome digitado tem " << nome.size() << " caracteres \n";

    return 1;
}