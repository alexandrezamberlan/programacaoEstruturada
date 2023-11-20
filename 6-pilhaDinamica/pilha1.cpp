#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

typedef struct no {
    string nome;
    struct no *prox;
} Celula;

Celula *inserir(string nome, Celula *topo){
    //alocar memoria
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores
    novo->nome = nome;

    //engatar
    novo->prox = topo;

    //retornar o primeiro
    return novo;
}

void exibir(Celula *topo) {
    if (!topo) {
        cout << "Estrutura vazia\n";
        return;
    }
    for (Celula *p = topo; p; p = p->prox) {
        cout << p->nome << endl;
    }
}

int contar(Celula *topo) {
    if (!topo) {        
        return 0;
    }
    int contador = 0;
    for (Celula *p = topo; p; p = p->prox) {
        contador++;
    }
    return contador;
}

Celula *remover(string nome, Celula *topo) {
	if (!topo) {
        cout << "Estrutura vazia\n";
        return topo;
    }
    Celula *p, *pR;
    for (pR = NULL, p = topo; p; pR = p, p = p->prox) {
    	if (nome == p->nome) {//numero encontrado
    		//eh o primeiro
    		if (p == topo) {
    			pR = p;
    			topo = p->prox;
    			free(pR);
    			return topo;
    		}  		
    		pR->prox = p->prox;
    		free(p);
    		break;
    	}
    }
    return topo;
}

Celula *ordenarBolha(Celula *topo) {
	Celula *p;
	string tmp;
	bool houveTroca;
	
	do {
		houveTroca = false;
		for (p = topo; p->prox; p = p->prox){
			if (p->nome > p->prox->nome) {
				tmp = p->nome;
				p->nome = p->prox->nome;
				p->prox->nome = tmp;
				houveTroca = true;
			}
		}
	} while (houveTroca);
	return topo;
}

int main() {
    Celula *entrada = NULL;

    entrada = inserir("Vinicius", entrada);
    entrada = inserir("Pedro", entrada);
    entrada = inserir("Bernardo", entrada);
    entrada = inserir("Felipe", entrada);

	entrada = ordenarBolha(entrada);

    exibir(entrada);
    
    cout << "Foram exibidas " << contar(entrada) << " celulas\n";

    return 1;
}
