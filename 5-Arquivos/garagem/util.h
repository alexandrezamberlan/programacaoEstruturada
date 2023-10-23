void inicializarVetor(Veiculo vetor[], int n){
    for (int i = 0; i < n; i++){
        vetor[i].placa = "";
        vetor[i].horaEntrada = "";
    }
}

int entrarGaragem(Veiculo vetor[], int n, int quantidadeCarros) {
    string placa, hora;
    bool carroLocalizado;
    cout << "Cadastro de Veiculo\n";

    if(quantidadeCarros == n){
        cout << "Garagem lotada!";        
    }
    else{
        while (true){
            cout << "Informe a placa em maiusculo: ";
            cin >> placa;
            if (placa.length() == 7){
                break;
            }
            else{
                cout << "Digite corretamente a placa!\n";
            }
        }
        while (true){
            cout << "Informe a hora de entrada [hh:mm]: ";
            cin >> hora;
            if (hora.length() == 5){
                break;
            }
            else{
                cout << "Digite corretamente a hora de entrada!\n";
            }
        }

        carroLocalizado = false;
        for(int i=0; i < n; i++){
            if(placa == vetor[i].placa){
                cout << "Carro já na garagem.\n";
                carroLocalizado = true;
                break;
            }
        }
        if(!carroLocalizado){
            for(int i=0; i < n; i++){
                if(vetor[i].placa == ""){
                    vetor[i].placa = placa;
                    vetor[i].horaEntrada = hora;
                    cout << "Carro inserido no sistema!\n";
                    quantidadeCarros++;
                    break;
                }
            }
        }
    }
    return quantidadeCarros;
}

void listarGaragem(Veiculo vetor[], int n, int quantidadeCarros) {
    cout << "Listagem de veiculos\n";
    if(quantidadeCarros == 0){
        cout << "Garagem vazia!\n";
    }
    else{
        for(int i = 0; i < n; i++){
            if(vetor[i].placa != ""){
                cout << "Placa: " << vetor[i].placa << endl;
            }
        }
    }
}

int sairGaragem(Veiculo vetor[], int n, int quantidadeCarros) {
    string placa, hora;
    bool carroLocalizado;
    cout << "Saida de Veiculo\n";

    if(quantidadeCarros == 0){
        cout << "Garagem vazia!\n";        
    } else {
        while (true){
            cout << "Informe a placa em maiusculo: ";
            cin >> placa;
            if (placa.length() == 7){
                break;
            }
            else{
                cout << "Digite corretamente a placa!\n";
            }
        }        
        carroLocalizado = false;
        for(int i=0; i < n; i++){
            if(placa == vetor[i].placa){
                //calcular tempo de estadia
                //horaSaida - horaEntrada...
                //calcular valor a ser cobrado
                //5 reais por hora ate 23h
                //liberar
                vetor[i].placa ="";
                vetor[i].horaEntrada="";
                quantidadeCarros--;
                carroLocalizado = true;
                cout << "Carro sendo retirado da garagem.\n";
                break;
            }
        }
        if(!carroLocalizado){
            cout << "Carro com esta placa nao localizado\n";
        } else {
            while (true){
            cout << "Informe a hora de saida [hh:mm]: ";
            cin >> hora;
            if (hora.length() == 5){
                break;
            }
            else{
                cout << "Digite corretamente a hora de saida!\n";
            }
        }
        }
    }
    return quantidadeCarros;
}