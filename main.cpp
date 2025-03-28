#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int scale;
    string option[3] = {"C°", "F°", "K"};
    float temperature;

    std::cout << "+-------------------------------+\n|    CONVERSOR DE TEMPERATURA   |\n+-------------------------------+\n";
    std::cout << "O que deseja converter?\n1- Celsius\n2 - Farenheit\n3 - Kelvin\n\n";
    
    do {
        std::cin >> scale;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "\033[2J\033[H";
            std::cout << "Entrada inválida\n";
            std::cout << "\n1- Celsius\n2 - Farenheit\n3 - Kelvin\n";

        } else if (scale < 1 || scale > 3)
        {
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "\033[2J\033[H";
            std::cout << "Digíte um número correspondente\n";
            std::cout << "\n1- Celsius\n2 - Farenheit\n3 - Kelvin\n";
        }
        

    } while(scale < 1 || scale > 3);

    std::cout << "\033[2J\033[H";
    std::cout << "Opção: " << option[scale - 1] << std::endl;

    return 0;
}