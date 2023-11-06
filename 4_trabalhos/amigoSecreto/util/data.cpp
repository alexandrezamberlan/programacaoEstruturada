#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    string dia = to_string(now->tm_mday);
    string mes = to_string(now->tm_mon + 1);
    string ano = to_string(now->tm_year + 1900);

    cout << "Data: " << dia << "/" << mes << "/" << ano << endl;
    return 0;
}