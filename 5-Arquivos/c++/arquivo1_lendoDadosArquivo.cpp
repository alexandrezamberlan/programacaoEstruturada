#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

int main() {
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
 
   		
	//le o arquivo capturando as frases
	string linha;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		// procuradorArquivo >> frase; //lendo palavra por palavra da linha 
		cout << linha << endl;
		//tratar a linha e extrair dados dela
	}

	procuradorArquivo.close();

    return 1;
}