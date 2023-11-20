#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct no {
    int numero;
    struct no *prox;
} Celula;

Celula *inserir(int numero, Celula *topo){
    //alocar memoria
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores
    novo->numero = numero;

    //engatar
    novo->prox = topo;

    //retornar o primeiro
    return novo;
}

Celula *remover(int numero, Celula *topo) {
	if (!topo) {
        cout << "Estrutura vazia\n";
        return topo;
    }
    Celula *p, *pR;
    for (pR = NULL, p = topo; p; pR = p, p = p->prox) {
    	if (numero == p->numero) {//numero encontrado
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

void exibir(Celula *topo) {
    if (!topo) {
        cout << "Estrutura vazia\n";
        return;
    }
    for (Celula *p = topo; p; p = p->prox) {
        cout << p->numero << endl;
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

Celula *ordenarBolha(Celula *topo) {
	Celula *p;
	int tmp;
	bool houveTroca;
	
	do {
		houveTroca = false;
		for (p = topo; p->prox; p = p->prox){
			if (p->numero > p->prox->numero) {
				tmp = p->numero;
				p->numero = p->prox->numero;
				p->prox->numero = tmp;
				houveTroca = true;
			}
		}
	} while (houveTroca);
	return topo;
}

int main() {
    Celula *entrada = NULL;

    srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		entrada = inserir(rand() % 100, entrada);
	}	

    exibir(entrada);
    
    cout << "Foram exibidas " << contar(entrada) << " celulas\n";
    
    int numero;
    cout << "Digite um numero para remover: ";
    cin >> numero;
    
    entrada = remover(numero, entrada);
    
    entrada = ordenarBolha(entrada);
    
    exibir(entrada);
    
    cout << "Foram exibidas " << contar(entrada) << " celulas\n";


    return 1;
}
