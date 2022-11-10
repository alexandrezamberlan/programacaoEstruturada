#include <bits/stdc++.h>
using namespace std;
 
void splitstr(string str, string deli = " ")
{
    int start = 0;
    int end = str.find(deli);
    while (end != -1) {
        cout << str.substr(start, end - start) << endl;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    cout << str.substr(start, end - start);
}

void split(string vetor[], string str, string deli = " ")
{        
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start, end - start);
}

int main()
{
    string s = "codigo;jogador;selecao;quantidade;especial;preco"; // Take any string with any delimiter 
    string vetor[6];
    split(vetor, s, ";");
    for (int i = 0; i < 6; i++) {
        cout << vetor[i] << endl;
    }
 
    return 0;
}
