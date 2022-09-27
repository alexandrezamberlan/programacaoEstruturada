#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL,"Portuguese");

    //abrir um arquivo texto e gravar nomes nele

    //solicita pro usuario nome do arquivo origem
	char nomeArquivo[200];
	cout << "Informe nome do arquivo que quer inserir dados: ";
	cin >> nomeArquivo;

    //criar um arquivo para escrita
	//https://www.tutorialspoint.com/cplusplus/cpp_files_streams
	ofstream procuradorArquivo;
	procuradorArquivo.open(nomeArquivo, ios::out | ios::app);

    string palavra;

    do {
        fflush(stdin);
        cout << "Escreva um nome para gravar no arquivo ou a palavra 'fim' para encerrar: ";
        getline(cin, palavra); //para pegar a linha inteira
        
        if (palavra == "fim") {
            break;
        }
        procuradorArquivo << palavra << endl;
    } while (1);

    procuradorArquivo.close();
    return 1;
}