#include <fstream>

typedef struct 
{
    string nome;
    string sigla;
    string valor;
} Cripto;

int conectarComBase(string nomeDaBase, Cripto lista[], int n) 
{
    ifstream leitor;
    leitor.open(nomeDaBase);
    
    int qtd = 0;

    if (!leitor)
    {
        cout << "Problemas para conectar com a base...\n";
        return qtd;
    }

    string linha;
    string vetor_linha[3];
    while (!leitor.eof() && qtd < n)
    {
        getline(leitor,linha);
        if (linha != "")
        {
            split(vetor_linha,linha,";");
            lista[qtd].nome = paraMaiusculo(vetor_linha[0]);
            lista[qtd].sigla = paraMaiusculo(vetor_linha[1]);
            lista[qtd].valor = vetor_linha[2];
            qtd++;
        }
    }
    leitor.close();
    return qtd;
}

void listar(Cripto lista[], int totalCadastrados)
{
    if (totalCadastrados == 0) 
    {
        cout << "Lista vazia\n";
    } else 
    {
        for (int i = 0; i < totalCadastrados; i++) 
        {
            cout << "Cripto: " << lista[i].nome << endl;
        }
        cout << "----------------\n";
        cout << "Total: " << totalCadastrados << endl;
    }
}

void atualizarCadastro(string nome, string sigla, string valor, string nomeDaBase)
{
    ofstream escritor;
    escritor.open(nomeDaBase, ios::out | ios::app);

    escritor << nome << ";" << sigla << ";" << valor << "\n";

    escritor.close();
}

void atualizarRemocao(Cripto lista[], int totalCadastrados, string nomeDaBase)
{
    ofstream escritor;
    escritor.open(nomeDaBase);
    for (int i = 0; i < totalCadastrados; i++)
    {
        escritor << lista[i].nome << ";" << lista[i].sigla << ";" << lista[i].valor << "\n";
    }

    escritor.close();
}

bool jaCadastrado(string nome, Cripto lista[], int totalCadastrados)
{
    for (int i = 0; i < totalCadastrados; i++)
    {
        if (nome == lista[i].nome)
        {
            return true; //ja cadastrado
        }
    }
    return false; //verificamos todas as posicoes e a cript nao cadastrada
}

int cadastrar(Cripto lista[], int totalCadastrados, int n, string nomeDaBase)
{
    if (totalCadastrados == n) 
    {
        cout << "Lista cheia\n";
    } else 
    {
        string nome;
        string sigla;
        string valor;
        cout << "Nome da cripto moeda: ";
        getline(cin, nome);
        nome = paraMaiusculo(nome);
        fflush(stdin);

        cout << "Sigla da cripto moeda: ";
        getline(cin, sigla);
        sigla = paraMaiusculo(sigla);
        fflush(stdin);

        cout << "Valor da cripto moeda: ";
        getline(cin, valor);
        fflush(stdin);

        if (jaCadastrado(nome, lista, totalCadastrados)) 
        {
            cout << "Cripto ja cadastrada....\n";
            return totalCadastrados;
        } else 
        {
            lista[totalCadastrados].nome = nome;
            lista[totalCadastrados].sigla = sigla;
            lista[totalCadastrados].valor = valor;  
            atualizarCadastro(nome, sigla, valor, nomeDaBase);          
        }
        return ++totalCadastrados;
    }
}

void copiarLista(Cripto origem[], Cripto destino[], int totalCadastrados)
{
    for (int i = 0; i < totalCadastrados; i++)
    {
        destino[i] = origem[i];
    }
}

int remover(Cripto lista[], int totalCadastrados, int n, string nomeDaBase)
{
    if (totalCadastrados == 0) 
    {
        cout << "Lista vazia\n";
    } else 
    {
        string nome;        
        cout << "Nome da cripto moeda a ser excluida: ";
        getline(cin, nome);
        nome = paraMaiusculo(nome);
        fflush(stdin);

        //procurar para excluir
        Cripto listaTMP[n];
        int j = 0;
        bool encontrou = false;
        for (int i = 0; i < totalCadastrados; i++) {
            if (nome != lista[i].nome) 
            {
                listaTMP[j] = lista[i];
                j++;

            } else {
                encontrou = true;
            }
        }
        //atualizar a lista original somente se encontrou
        if (!encontrou)
        {
            cout << "Cripto nao localizada\n";
            return totalCadastrados;
        } else
        {
            totalCadastrados--;
            copiarLista(listaTMP, lista, totalCadastrados);
            atualizarRemocao(listaTMP, totalCadastrados, nomeDaBase);
        }
        
        return totalCadastrados;
    }
}

void menu(Cripto lista[], int totalCadastrados, int n, string nomeDaBase)
{
    int opcao;
    do
    {
        system("cls");
        cout << "MENU\n";
        cout << "1 - Listar criptos\n";
        cout << "2 - Cadastrar cripto\n";
        cout << "3 - Remover cripto\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            cout << "Listagem de criptos.....\n";
            listar(lista, totalCadastrados);
            break;
        case 2:
            cout << "Cadastro de cripto.....\n";
            totalCadastrados = cadastrar(lista, totalCadastrados, n, nomeDaBase);
            break;
        case 3:
            cout << "Remocao de cripto.....\n";
            totalCadastrados = remover(lista, totalCadastrados, n, nomeDaBase);
            break;
        case 4:
            cout << "Tchau.....\n";
            break;        
        default:
            cout << "Opcao invalida.....\n";
            break;
        }
        system("pause");        
    } while (opcao != 4);    
}
