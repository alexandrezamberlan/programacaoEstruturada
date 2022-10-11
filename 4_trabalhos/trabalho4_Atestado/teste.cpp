#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string linha = "nome;email;matricula";
    cout << linha << endl;
    cout << linha.find(";") << endl;
    cout << linha.find_last_of(";") << endl;


    

    return 1;
}