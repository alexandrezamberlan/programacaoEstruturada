#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string linha = "nome;email;matricula";
  cout << linha << endl;
  int primeiro = linha.find(";");
  int ultimo = linha.find_last_of(";");
  cout << primeiro << endl;
  cout << ultimo << endl;

  cout << linha.substr(0, primeiro) << endl;

  cout << linha.substr(ultimo + 1, 200) << endl;

  cout << linha.substr(primeiro + 1, ultimo - (primeiro+1)) << endl;

  return 1;
}