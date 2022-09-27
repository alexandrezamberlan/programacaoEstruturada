// Faça um programa que leia um arquivo baseado neste formato:
// nome da pessoa@curso@esporte preferido

#include <iostream>
#include <fstream>
#include <string>
#include "../../util.h"
#define TAM 1000


using namespace std;

typedef struct 
{
    string nome;
    string curso;
    string esporte;
} Aluno;

void popularVetorDoArquivo(Aluno *vetor, int *i) {
    //abrir um arquivo texto e exibir seu conteudo na tela

    //solicita pro usuario nome do arquivo origem
	char nomeArquivo[200];
	cout << "Informe nome do arquivo que quer exibir na tela: ";
	cin >> nomeArquivo;
    
    //abrir arquivo para leitura
	//https://www.tutorialspoint.com/cplusplus/cpp_files_streams
	ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 

    if (!procuradorArquivo) {
        cout << "Arquivo não localizado. Programa encerrado." << endl;
        exit(0);
    }
 
   	string *resposta;
    
	//le o arquivo capturando as frases
	string frase;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,frase); //lendo a linha inteira
        resposta = split(frase,"@");
        //resposta[0] = nome do aluno
        //resposta[1] = curso do aluno
        //resposta[2] = esporte do aluno

        vetor[*i].nome = resposta[0];
        vetor[*i].curso = resposta[1];
        vetor[*i].esporte = resposta[2];
        *i = *i + 1;
	}

	procuradorArquivo.close();
}

string pegarPrimeiroNome(string nome)
{
    return "";
}

void exibirVetor(Aluno *vetor, int n)
{
    for (int i = 0; i < n; i++) 
    {
        cout << pegarPrimeiroNome(vetor[i].nome) << " - " << vetor[i].esporte << endl;
    }
}


int main()
{
    Aluno vetor[TAM];
    int i = 0;
    popularVetorDoArquivo(vetor, &i);

    exibirVetor(vetor, i);
 
    return 0;
}