#include <fstream>
#include "../util/split.h"

void gravarPessoa(string nome, string email) {
    ofstream procuradorArquivo;
	procuradorArquivo.open("amigos.csv", ios::out | ios::app);
    procuradorArquivo << nome << ";" << email << "\n";   

    procuradorArquivo.close();
}

void gravarAmigoSecreto(Pessoa vetor[], int totalInscritos, Pessoa vetorTMP[]) {
    ofstream procuradorArquivo;
	procuradorArquivo.open("amigosSecretos.csv");
    //nome;email;nomeAmigo;emailAmigo
    for (int i = 0; i < totalInscritos; i++) {
        procuradorArquivo << vetor[i].nome << ";" << vetor[i].email << ";" << vetorTMP[i].nome << ";" << vetorTMP[i].email << endl;
    }    

    procuradorArquivo.close();
}

int conectarBase(Pessoa vetor[], int n) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    int totalInscritos = 0;

    procuradorArquivo.open("amigos.csv"); 

    if (!procuradorArquivo) {        
        return totalInscritos;
    }
   		
	//le o arquivo capturando as frases
	string linha;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		string vetor_linha[2];
        split(vetor_linha,linha,";");

        vetor[totalInscritos].nome = vetor_linha[0];
        vetor[totalInscritos].email = vetor_linha[1];
        totalInscritos++;
	}

	procuradorArquivo.close();
    return totalInscritos;
}
