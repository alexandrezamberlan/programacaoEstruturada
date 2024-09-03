#include <ctime>

void popularVetor(int vetor[], int n) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100;
    }
}

void exibirVetor(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        cout << vetor[i] << endl;
    }
}

void escreverMenor(int vetor[], int n) {
    int menor = vetor[0];
    for (int i = 1; i < n; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    cout << "Procedimento: o menor valor eh: " << menor << endl;
}

int pegarMenor(int vetor[], int n) {
    int menor = vetor[0];
    for (int i = 1; i < n; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    return menor;
}

void escreverSoma(int vetor[], int n) {
    int resultado = 0;
    for (int i = 0; i < n; i++) {
        resultado = resultado + vetor[i];
    }
    cout << "Procedimento: a soma dos elementos eh: " << resultado << endl;
}

int somar(int vetor[], int n) {
    int resultado = 0;
    for (int i = 0; i < n; i++) {
        resultado = resultado + vetor[i];
    }
    return resultado;
}

void substituirPares(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        if (vetor[i] % 2 == 0) {
            vetor[i] = 0;
        }
    }
}

void copiarVetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}


string adivinha(string nome) {
    string primeiroNome = "";
    int i;
    for (i = 0; i < nome.length() ; i++) {
        if (nome[i] == ' ' || nome[i] == '\0' || nome[i] == '\n') {
            break;
        }       
        primeiroNome.append(1,nome[i]);
    }    
    return primeiroNome;
}
