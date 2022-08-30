#include <iostream> //cin e cout
#include <string> //

using namespace std; //omitir o std na frente do cin, por exemplo 

#include "util.h"


int main() {
    string nome;
    string email;

    cout << "Digite um nome completo: ";
    getline(cin, nome);

    nome = paraMaiusculo(nome);

    string primeiroNome = pegarPrimeiroNome(nome);
    //string sobreNome = pegarSobreNome(nome);
    cout << sobreNome << endl;

    return 1;
}