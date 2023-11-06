#include "../util/string.h"

bool jaInscrito(string nome, Pessoa vetor[], int n) {
    for (int i = 0; i < n; i++) {
        if (vetor[i].nome == nome) {
            return true;
        }
    }
    return false;
}

int cadastrarPessoa(Pessoa vetor[], int n, int totalInscritos){
    string nome;
    string email;

    if (n == totalInscritos) {        
        return totalInscritos;
    }

    cout << "Digite nome: ";
    getline(cin,nome);
    fflush(stdin);

    //validar nome e conferir na vetor
    if (jaInscrito(nome,vetor,n)){
        cout << "Este nome ja inscrito no evento\n";
        return totalInscritos;
    }
    
    cout << "Email: ";
    cin >> email;
    fflush(stdin);

    nome = paraMaiusculo(nome);
    email = paraMaiusculo(email);

    vetor[totalInscritos].nome = nome;
    vetor[totalInscritos].email = email;    


    gravarPessoa(nome,email);
    return ++totalInscritos;
}

void listarPessoas(Pessoa vetor[], int totalInscritos){
    
    for (int i = 0; i < totalInscritos; i++) {
        cout << vetor[i].nome << " : " << vetor[i].email << endl;
    }    
}

bool verificarSeDiferentes(Pessoa vetor[], int totalInscritos, Pessoa vetorTMP[]) {
    for (int i = 0; i < totalInscritos; i++) {
        if (vetor[i].nome == vetorTMP[i].nome) {
            return false;
        }
    }
    return true;
}

// embaralhando um array
void shuffle_array(Pessoa arr[], int n)
{
	// To obtain a time-based seed
	unsigned seed = 0;

	// Shuffling our array
	shuffle(arr, arr + n, default_random_engine(seed));
}

void gerarAmigoSecreto(Pessoa vetor[], int totalInscritos) {
    //verificar se a vetor existe
    Pessoa vetorTMP[totalInscritos];
    if (totalInscritos == 0) {
        return;
    }

    for (int i = 0; i < totalInscritos; i++) {
        vetorTMP[i] = vetor[i];
    }

    //verificar se as vetors estão totalmente diferentes    
    do {
        //embaralhar a vetorTMP
        shuffle_array(vetorTMP, totalInscritos);
    } while(verificarSeDiferentes(vetor, totalInscritos, vetorTMP) == true);

    //gravar na base a vetor de amigos secretos
    gravarAmigoSecreto(vetor, totalInscritos, vetorTMP);

}