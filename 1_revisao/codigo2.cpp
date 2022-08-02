#include <iostream>
#include <locale> 

using namespace std;

int main() {
    //setlocale(LC_ALL, "pt_BR");
    //locale brasilLocale("pt_BR");
    int idade;

    cout << "Digite sua idade é: ";
    cin >> idade;

    cout << "Voce ja dormiu " << idade / 3 << " anos desde que nasceu \n";

    return 1;
}