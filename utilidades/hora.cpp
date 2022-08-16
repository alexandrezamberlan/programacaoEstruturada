#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    string hora = to_string(now->tm_hour);
    string minutos = to_string(now->tm_min); 

    cout << "Hora: " << hora << ":" << minutos << endl;
    return 0;
}
