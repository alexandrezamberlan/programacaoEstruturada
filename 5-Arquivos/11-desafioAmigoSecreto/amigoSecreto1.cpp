#include <iostream>
#include <string>
#include <cstring>
#include <locale.h>
#include <sstream>
#include <time.h>
#include <ctime> 
#include <fstream>
#include <stdio.h>

#define TAM 100
#define NOMEARQUIVO "amigos.dat"

using namespace std;

typedef struct {
    string nome;
    string email; 
    string nomeAmigo;
    string emailAmigo;
} AmigoSecreto;

void inicializarVetor(AmigoSecreto vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i].nome = " ";
        vetor[i].email = " ";
        vetor[i].nomeAmigo = " ";
        vetor[i].emailAmigo = " ";
    }
}

void converte(string linha, string *nome, string *email, 
                            string *nomeAmigo, string *emailAmigo) {
	stringstream sNome, 
	             sEmail, 
		         sNomeAmigo,
                 sEmailAmigo;
	int parteLinha = 0; //0 para nome; 1 para email; 2 para amigo ,...
	int i;
	for (i = 0; linha[i] != ' '; i++) {
		sNome << linha[i];
	}
	sNome << "\0";
	stringstream conversaoNome(sNome.str());
	conversaoNome >> *nome;
	
	for (++i; linha[i] != ' '; i++) {
		sEmail << linha[i];
	}
	sEmail << "\0";
	stringstream conversaoEmail(sEmail.str());
	conversaoEmail >> *email;

    for (++i; linha[i] != ' '; i++) {
		sNomeAmigo << linha[i];
	}
	sNomeAmigo << "\0";
	stringstream conversaoNomeAmigo(sNomeAmigo.str());
	conversaoNomeAmigo >> *nomeAmigo;
	
	for (++i; i < linha.length(); i++) {
		sEmailAmigo << linha[i];
	}
	sEmailAmigo << "\0";
	stringstream conversaoEmailAmigo(sEmailAmigo.str());
	conversaoEmailAmigo >> *emailAmigo;
}

int populaVetorAmigosArquivo(ifstream &procurador, AmigoSecreto vetor[], int n) {
    string conteudoLinha;
    int i = 0;
    //transferir o conteudo do arquivo para o vetor garagem
    while (getline(procurador,conteudoLinha)) {
        //cout << conteudoLinha << endl;
        converte(conteudoLinha, &vetor[i].nome,
		                        &vetor[i].email,
								&vetor[i].nomeAmigo,
                                &vetor[i].emailAmigo);
        i++;
        
    }
    return i;
}

string paraMaiusculo(string palavra) {
	int i = 0;
    do{
        if ( palavra[i] == '\n' || palavra[i] == '\0')
        {      
            break;
        }
        palavra[i] = toupper(palavra[i]);
        i++;
    }while (1);

	return palavra;
}

void atualizaArquivoComAmigos(AmigoSecreto vetor[], int n) {
	ofstream procuradorEscrita;
	procuradorEscrita.open(NOMEARQUIVO);
	
	for (int i = 0; i < n; i++) {
		if (vetor[i].nome != " ") {
			procuradorEscrita << vetor[i].nome 
			     << " " << vetor[i].email 
				 << " " << vetor[i].nomeAmigo 
                 << " " << vetor[i].emailAmigo << endl;
		}
	}
	procuradorEscrita.close();
}

int jaExisteAmigo(string nome, AmigoSecreto vetor[], int n) {
    for (int i = 0; i < n; i++) {
        if (nome == vetor[i].nome) return 1;
    }
    return 0;
}

void cadastraAmigo(AmigoSecreto vetor[], int n) {
	int i;
    string nome;
	for (i = 0; i < n; i++){
		if (vetor[i].nome == " ") {
			break;
		}
	}        				         	
	cin.ignore(); //equivale ao fflush do c
	cout << "Nome: ";    
	getline(cin,  nome);
    nome = paraMaiusculo(nome);

    if (jaExisteAmigo(nome,vetor,n)) {
        cout << "Amigo ja cadastrado!" << endl;
        return;
    }
    vetor[i].nome = nome;
    //cin.ignore(); //equivale ao fflush do c
    cout << "Email: ";
	cin >> vetor[i].email;
	atualizaArquivoComAmigos(vetor, n);
	cout << "Amigo cadastrado com sucesso" << endl;
}

int editandoAmigo(AmigoSecreto vetor[], int n, int qtdAmigos) {
	int i, opcao;
	string nome;
    cin.ignore(); //equivale ao fflush do c
	cout << "Nome para pesquisa: ";
	getline(cin, nome);
    nome = paraMaiusculo(nome);

    for (i = 0; i < n; i++) {
        if (nome == vetor[i].nome) {
            cout << "Amigo localizado" << endl;
        
            cout << "1 - atualiza; 2 - remove; 3 - sai: ";
            cin >> opcao;
            switch (opcao) {
                case 1 : 
                    cin.ignore(); //equivale ao fflush do c
                    cout << "Novo email: ";
                    cin >> vetor[i].email;
                    atualizaArquivoComAmigos(vetor, n);
                    cout << "Amigo atualizado com sucesso" << endl; 
                    return qtdAmigos;
                case 2 : 
                    cout << "Apagando amigo...." << endl;
                    vetor[i].nome = " ";
                    vetor[i].email = " ";
                    vetor[i].nomeAmigo = " ";
                    vetor[i].emailAmigo = " ";
                    qtdAmigos--;
                    atualizaArquivoComAmigos(vetor, n);
                    cout << "Amigo apagado com sucesso" << endl; 
                    return qtdAmigos;
                case 3 : 
                    cout << "Voce decidiu nao fazer nada" << endl;
                    return qtdAmigos; 
                default : cout << "Opcao invalida" << endl;
            }
        }
    }//fim do for
    
    cout << "Amigo nao localizado" << endl;
    return qtdAmigos;
}

int jaExiste(int valor, int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        if (valor == vetor[i]) return 1;
    }
    return 0;
}

void sortearAmigos(AmigoSecreto vetor[], int qtdAmigos) {
    srand(time(NULL));
    int vetorSorteio[qtdAmigos];
    
    int i = 0;
    int valor;
    do {
        do {
            valor = rand() % qtdAmigos;
        } while (jaExiste(valor,vetorSorteio,i) || valor == i);

        vetorSorteio[i] = valor;
        i++;
    } while (i < qtdAmigos);
    cout << "gerei lista amigos" << endl;

    for (int i = 0; i < qtdAmigos; i++) {
        vetor[i].nomeAmigo = vetor[ vetorSorteio[i] ].nome;
        vetor[i].emailAmigo = vetor[ vetorSorteio[i] ].email;
    }

    atualizaArquivoComAmigos(vetor, qtdAmigos);  
    cout << "terminou" << endl; 
}

int main() {
    AmigoSecreto vetor[TAM];
    int opcao;
    int qtdAmigos;
    inicializarVetor(vetor,TAM);

    ofstream procuradorEscrita;
    ifstream procuradorLeitura;
    procuradorLeitura.open(NOMEARQUIVO);
    if (procuradorLeitura) {
        //popula vetor
        qtdAmigos = populaVetorAmigosArquivo(procuradorLeitura, vetor, TAM);
        cout << "Arquivo lido para vetor" << endl;
        procuradorLeitura.close();
    } else {
        //cria arquivo
        procuradorEscrita.open(NOMEARQUIVO);
        procuradorEscrita.close();
    }

    do {
        cout << "Menu Amigo Secreto" << endl;
        cout << "1 - Cadastrar amigos" << endl;
        cout << "2 - Editar amigos" << endl;
        cout << "3 - Gerar amigo secreto" << endl;
        cout << "4 - Enviar email" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        switch (opcao)
        {
            case 1 :
                cout << "Cadastrando amigos" << endl;
                qtdAmigos++;
			    cadastraAmigo(vetor, TAM);
                break;
            case 2 :   
                cout << "Editando amigos"  << endl;
                qtdAmigos = editandoAmigo(vetor, TAM, qtdAmigos);
                break;            
            case 3 :
                cout << "Sorteando amigo secreto" << endl;
                sortearAmigos(vetor, qtdAmigos);
                cout << "Amigo secreto gerado" << endl;
                break;
            case 4 :   
                cout << "Preparando para enviar por email!!" << endl;
                break;
            case 5 : cout << "Obrigado por usar o sistema" << endl;   
                break;                
            default: cout << "Opcao invalida. Redigite" << endl;
            break;
        }
    } while (opcao != 5);

    return 1;
}