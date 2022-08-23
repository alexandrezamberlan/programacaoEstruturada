void popularVetor(int v[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100;
    }
}

void exibirVetor(int v[], int n, string frase) {
    cout << frase;
    for (int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
}