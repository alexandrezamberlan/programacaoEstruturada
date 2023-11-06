#include <cstring>

string paraMaiusculo(string frase) { //para C++ como passagem de parametro por valor
    int i;
    for (i = 0; i < frase.length(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}