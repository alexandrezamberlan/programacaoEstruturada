#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string horaE = "19:36";
    string hora = horaE.substr(0,2);
    string minutos = horaE.substr(3,2);
    cout << hora << endl;
    cout << minutos << endl;

    int tempoPermanencia = stoi(hora) * 60 + stoi(minutos);
    cout << "Permanencia: " << tempoPermanencia << endl;


    string umaFrase = "Eu sou o alexandre zamberlan";
    cout << umaFrase.find("andre");

    return 0;
}
