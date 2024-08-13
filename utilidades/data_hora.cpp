#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;

int main() {
    // Obtém o tempo atual do sistema
    auto agora = chrono::system_clock::now();

    // Converte para o tipo de tempo C do sistema
    time_t tempo_agora = chrono::system_clock::to_time_t(agora);

    // Converte para a estrutura tm para manipulação mais fácil
    tm* data_hora = localtime(&tempo_agora);

    // Exibe a data e a hora formatada
    cout << "Data e hora atuais: "
              << put_time(data_hora, "%d/%m/%Y - %H:%M:%S")
              << endl;

    return 0;
}
