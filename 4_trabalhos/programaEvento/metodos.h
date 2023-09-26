#include <fstream>
#include "util.h"

int conectarBase(Participante vetor[], int n) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    int totalInscritos = 0;

    for (int i = 0; i < n; i++) {
        vetor[i].matricula = "";
        vetor[i].nome = "";
        vetor[i].email = "";
    }
    procuradorArquivo.open("inscritos.csv"); 

    if (!procuradorArquivo) {        
        return totalInscritos;
    }
   		
 
	//le o arquivo capturando as frases
	string linha;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		string vetor_linha[3];
        split(vetor_linha,linha,";");

		vetor[totalInscritos].matricula = vetor_linha[0];
        vetor[totalInscritos].nome = vetor_linha[1];
        vetor[totalInscritos].email = vetor_linha[2];
        totalInscritos++;
	}

	procuradorArquivo.close();
    return totalInscritos;
}

bool jaInscrito(string matricula, Participante vetor[], int n) {
    for (int i = 0; i < n; i++) {
        if (vetor[i].matricula == matricula) {
            return true;
        }
    }
    return false;
}

void adicionarInscritoVetor(Participante vetor[],int n,string matricula,string nome,string email) {
    for (int i = 0; i < n; i++) {
        if (vetor[i].matricula == ""){
            vetor[i].matricula = matricula;
            vetor[i].nome = nome;
            vetor[i].email = email;
            break;
        }
    }
}

void adicionarInscritoArquivo(string matricula, string nome, string email) {
    ofstream procuradorArquivo;
	procuradorArquivo.open("inscritos.csv", ios::out | ios::app);
    procuradorArquivo << matricula << ";" << nome << ";" << email << "\n";   

    procuradorArquivo.close();
}

int inscricao(Participante vetor[], int n, int totalInscritos) {
    cout << "INSCRICAO\n";
    string matricula;
    string nome;
    string email;

    if (TAM == totalInscritos) {
        cout << "Evento lotado\n";
        return totalInscritos;
    }
    cout << "Informe matricula: ";
    cin >> matricula;
    fflush(stdin);
    if (jaInscrito(matricula,vetor,n)){
        cout << "Esta matricula ja inscrita no evento\n";
        return totalInscritos;
    }
    cout << "Nome Completo: ";
    getline(cin, nome);
    fflush(stdin);

    cout << "Email: ";
    cin >> email;
    fflush(stdin);
    nome = paraMaiusculo(nome);
    email = paraMaiusculo(email);
    adicionarInscritoVetor(vetor,n,matricula,nome,email);
    adicionarInscritoArquivo(matricula,nome,email);
    
    return ++totalInscritos;
}

void listagem(Participante vetor[], int totalInscritos) {
    cout << "LISTAGEM INSCRITOS\n";
    for (int i = 0; i < totalInscritos; i++) {
        cout << vetor[i].matricula << ":" << vetor[i].nome << endl;
    }
}

void menu(Participante vetor[], int n, int totalInscritos) {  
    int opcao;
    do {
        system("cls");
        cout << "MENU" << endl;
        cout << "1 - Inscrever em evento\n";
        cout << "2 - Listar inscritos\n";
        cout << "3 - Registrar entrada\n";
        cout << "4 - Registrar saida\n";
        cout << "5 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        switch (opcao) {
        case 1:
            cout << "Inscrever em evento\n";
            totalInscritos = inscricao(vetor, n, totalInscritos);
            break;
        case 2:
            cout << "Listar inscritos\n";
            listagem(vetor,totalInscritos);
            break;
        case 3:
            cout << "Registrar entrada\n";
            break;
        case 4:
            cout << "Registrar saida\n";
            break;
        case 5:            
            exit(1);
        default:
            cout << "Opcao invalida\n";
            break;
        } 


        system("pause");
    } while (true);
}