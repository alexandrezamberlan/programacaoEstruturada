typedef struct {
    string nome;
    string email;
    string telefone; 
} Contato; //tipo artificial construido pelo programador

string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.length(); i++)
    {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

string pegarPrimeiroNome(string nome) {
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

void inicializar(Contato vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i].nome = "";
        vetor[i].email = "";
        vetor[i].telefone = "";
    }
}

bool validaNomeCompleto(string nome) {
    for (int i = 0; i < nome.length(); i++) {
        if (nome[i] == ' ' && (nome[i+1] != ' ' || nome[i+1] != '\n')){
            return true;
        }
    }
    return false;
}

bool inserir(Contato vetor[], int *qtd) {
    if (*qtd == TAM) {
        return false;
    } /*else*/
    string nome, email;
    for (int i = 0; i < TAM; i++) {
        if (vetor[i].nome == "") {
            *qtd = *qtd + 1; //(*qtd)++
            
            //recebendo um nome
            do {
                cout << "Entre com nome completo: ";
                getline(cin, nome);
                nome = paraMaiusculo(nome);
            } while (!validaNomeCompleto(nome));
            vetor[i].nome = nome;

            //recebendo um email
            cout << "Entre com email valido: ";
            getline(cin, email);
            email = paraMaiusculo(email);
            vetor[i].email = email;

            //recebendo um telefone
            cout << "Entre com seu telefone celular: ";
            getline(cin, vetor[i].telefone);   
            break;        
        }
    }    
    return true;
}

bool listar(Contato vetor[], int qtd) {
    if (qtd == 0) return false;

    for (int i = 0; i < qtd; i++) {
        if (vetor[i].nome != "") {
            cout << "Nome: " << vetor[i].nome << endl;
            cout << "Email: " << vetor[i].email << endl;
            cout << "Telefone: " << vetor[i].telefone << endl;
            cout << "--------------------------------------" << endl;
        }
    }
    return true;
}

bool pesquisar(Contato vetor[], int qtd) {
    if (qtd == 0) return false;
    string nomePesquisa;
    cout << "Digite parte do nome ou nome completo: ";
    getline(cin,nomePesquisa);
    nomePesquisa = paraMaiusculo(nomePesquisa);

    for (int i = 0; i < qtd; i++) {
        if (vetor[i].nome != "") {
            if (vetor[i].nome.find(nomePesquisa) != -1) {
                cout << "Nome: " << vetor[i].nome << endl;
                cout << "Email: " << vetor[i].email << endl;
                cout << "Telefone: " << vetor[i].telefone << endl;
                cout << "--------------------------------------" << endl;
            }
        }
    }
    return true;
}

bool remover(Contato vetor[], int *qtd) {
    if (*qtd == 0) return false;
    string nomePesquisa;
    cout << "Digite parte do nome ou nome completo: ";
    getline(cin,nomePesquisa);
    nomePesquisa = paraMaiusculo(nomePesquisa);
    int confirma;

    for (int i = 0; i < *qtd; i++) {
        if (vetor[i].nome != "") {
            if (vetor[i].nome == nomePesquisa) {
                cout << "Nome: " << vetor[i].nome << endl;
                cout << "Email: " << vetor[i].email << endl;
                cout << "Telefone: " << vetor[i].telefone << endl;
                cout << "1 - Confirma a remocao; 2 - Aborta a remocao!";
                cin >> confirma;

                if (confirma == 1) {
                    vetor[i].nome = "";
                    vetor[i].email = "";
                    vetor[i].telefone = "";
                    *qtd = *qtd - 1;
                    return true;
                } 
            }
        }
    }
    return false;
}

bool atualizar(Contato vetor[], int qtd) {
    if (qtd == 0) return false;
    string nomePesquisa;
    string nome, email, telefone;
    cout << "Digite parte do nome ou nome completo: ";
    getline(cin,nomePesquisa);
    nomePesquisa = paraMaiusculo(nomePesquisa);
    int confirma;

    for (int i = 0; i < qtd; i++) {
        if (vetor[i].nome != "") {
            if (vetor[i].nome == nomePesquisa) {
                cout << "Nome: " << vetor[i].nome << endl;
                cout << "Email: " << vetor[i].email << endl;
                cout << "Telefone: " << vetor[i].telefone << endl;
                cout << "1 - Confirma a atualizacao; 2 - Aborta a atualizacao!";
                cin >> confirma;
                fflush(stdin);

                if (confirma == 1) {
                    //recebendo um nome
                    do {
                        cout << "Entre com nome completo: ";
                        getline(cin, nome);                        
                        nome = paraMaiusculo(nome);
                    } while (!validaNomeCompleto(nome));
                    vetor[i].nome = nome;

                    //recebendo um email
                    cout << "Entre com email valido: ";
                    getline(cin, email);
                    email = paraMaiusculo(email);
                    vetor[i].email = email;

                    //recebendo um telefone
                    cout << "Entre com seu telefone celular: ";
                    getline(cin, vetor[i].telefone);   
                    return true;
                }                 
            }
        }
    }
    return true;
}