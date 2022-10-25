#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct nodo {
    string nome;
    struct nodo *prox; //prox é um ponteiro para o próximo elemento da pilha
} Celula;


Celula *inserir(string nome, Celula *pilha) {
    Celula *novo;

    //alocação de memoria
    novo = (Celula *)malloc(sizeof(Celula));

    //deposito dos valores de parametros para a celula
    novo->nome = nome;
    novo->prox = pilha;

    //engata
    return novo;
}

void exibir(Celula *pilha) {
    if (!pilha) {
        cout << "Estrutura vazia" << endl;
    } else {
        Celula *p;
        for (p = pilha; p; p = p->prox) {
            cout << p->nome << "  ";
        }
    }
    cout << endl;
}

Celula *popularPilha(string nomeArquivo) {
    Celula *pilha = NULL;
    ifstream leitor;
    leitor.open(nomeArquivo);
    string linha;
    while (!leitor.eof()) {
		getline(leitor,linha); 
        pilha = inserir(linha,pilha);
    }

    leitor.close();
    return pilha;
}

int contarNos(Celula *pilha) {
  int quantidade = 0;
  Celula *p;
  for (p = pilha; p; p = p->prox) {
    quantidade++;
  }
  return quantidade;
}

Celula *pegarEndereco(string nome, Celula *pilha) {
  if (!pilha) return NULL;
  Celula *p;

  for (p = pilha; p; p = p->prox) {
    if (nome == p->nome) {
      return p;
    }
  }
  return NULL;
}

int main() {
    Celula *pilha = NULL;
    string nomeArquivo = "nomes.txt";
    pilha = popularPilha(nomeArquivo);

    cout << "Quantidade de elementos: " << contarNos(pilha) << endl;
    exibir(pilha); //nao ha alteracao na pilha

    string nomePesquisa;
    cout << "Nome para pesquisa: ";
    getline(cin, nomePesquisa);

    cout << nomePesquisa << " esta na posicao " << pegarEndereco(nomePesquisa, pilha) << endl;

    return 1;
}