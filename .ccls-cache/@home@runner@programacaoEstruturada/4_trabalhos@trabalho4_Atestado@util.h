#include <bits/stdc++.h>

string paraMaiusculo(string frase) {
  for (int i = 0; i < frase.length(); i++) {
    frase[i] = toupper(frase[i]);
  }
  return frase;
}

string pegarPrimeiroNome(string nome) {
  string primeiroNome = "";
  int i;
  for (i = 0; i < nome.length(); i++) {
    if (nome[i] == ' ' || nome[i] == '\0' || nome[i] == '\n') {
      break;
    }
    primeiroNome.append(1, nome[i]);
  }
  return primeiroNome;
}

bool validaNomeCompleto(string nome) {
  for (int i = 0; i < nome.length(); i++) {
    if (nome[i] == ' ' && (nome[i + 1] != ' ' || nome[i + 1] != '\n')) {
      return true;
    }
  }
  return false;
}

void splitstr(string str, string deli = " ") {
  int start = 0;
  int end = str.find(deli);
  while (end != -1) {
    cout << str.substr(start, end - start) << endl;
    start = end + deli.size();
    end = str.find(deli, start);
  }
  cout << str.substr(start, end - start);
}