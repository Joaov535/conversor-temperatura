#include <iostream>
#include <limits>
using namespace std;

class Temperature
{
public:
    float value;

    void convertCelsiusToFahrenheit()
    {
        value = value + (9.0 / 5.0) + 32.0;
    }

    void convertFahrenheitToCelsius()
    {
        value = (value - 32.0) * (5.0 / 9.0);
    }

    void convertCelsiusToKelvin()
    {
        value += 273.0;
    }

    void convertKelvinToCelsius()
    {
        value -= 273.0;
    }

    void convertFahrenheitToKelvin()
    {
        convertFahrenheitToCelsius();
        convertCelsiusToKelvin();
    }

    void convertKelvinToFahrenheit()
    {
        convertKelvinToCelsius();
        convertCelsiusToFahrenheit();
    }
};

int getScaleFrom()
{
    int value;

    std::cout << "\033[2J\033[H";
    std::cout << "+-------------------------------+\n|    CONVERSOR DE TEMPERATURA   |\n+-------------------------------+\n";
    std::cout << "O que deseja converter?\n1- Celsius\n2 - Fahrenheit\n3 - Kelvin\n\n";

    do
    {
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "\033[2J\033[H";
            std::cout << "Entrada inválida\n";
            std::cout << "\n1- Celsius\n2 - Fahrenheit\n3 - Kelvin\n";
        }
        else if (value < 1 || value > 3)
        {
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "\033[2J\033[H";
            std::cout << "Digíte um número correspondente\n";
            std::cout << "\n1- Celsius\n2 - Fahrenheit\n3 - Kelvin\n";
        }

    } while (value < 1 || value > 3);

    return value;
}

int getScaleTo()
{
    int value;

    std::cout << "\033[2J\033[H";
    std::cout << "+-------------------------------+\n|    CONVERSOR DE TEMPERATURA   |\n+-------------------------------+\n";
    std::cout << "Para qual deseja converter?\n1- Celsius\n2 - Fahrenheit\n3 - Kelvin\n\n";

    do
    {
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "\033[2J\033[H";
            std::cout << "Entrada inválida\n";
            std::cout << "\n1- Celsius\n2 - Fahrenheit\n3 - Kelvin\n";
        }
        else if (value < 1 || value > 3)
        {
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "\033[2J\033[H";
            std::cout << "Digíte um número correspondente\n";
            std::cout << "\n1- Celsius\n2 - Fahrenheit\n3 - Kelvin\n";
        }

    } while (value < 1 || value > 3);

    return value;
}

float getTemperature()
{
    float value;

    std::cout << "\033[2J\033[H";
    std::cout << "+-------------------------------+\n|    CONVERSOR DE TEMPERATURA   |\n+-------------------------------+\n";
    std::cout << "Digíte a temperatura a converter\n";
    while (true)
    {
        std::cin >> value;
        if (!std::cin.fail())
            break;

        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cout << "\033[2J\033[H";
        std::cout << "Entrada inválida\n";
        std::cout << "Digite apenas o valor em números: \n";
    }
    return value;
}

int main()
{
    while (true)
    {

        int scaleFrom, scaleTo;
        string option[3] = {"C°", "F°", "K"};
        float value;

        scaleFrom = getScaleFrom();
        scaleTo = getScaleTo();

        value = getTemperature();

        Temperature t;
        t.value = value;

        switch (scaleFrom)
        {
        case 1:
            if (option[scaleTo - 1] == "F°")
            {
                t.convertCelsiusToFahrenheit();
            }
            else if (option[scaleTo - 1] == "K")
            {
                t.convertCelsiusToKelvin();
            }
            break;
        case 2:
            if (option[scaleTo - 1] == "C°")
            {
                t.convertFahrenheitToCelsius();
            }
            else if (option[scaleTo - 1] == "K")
            {
                t.convertFahrenheitToKelvin();
            }
            break;

        case 3:
            if (option[scaleTo - 1] == "C°")
            {
                t.convertKelvinToCelsius();
            }
            else if (option[scaleTo - 1] == "F°")
            {
                t.convertKelvinToFahrenheit();
            }

            break;
        default:
            break;
        }

        std::cout << "\033[2J\033[H";
        std::cout << "A temperatura em " << option[scaleTo - 1] << " é: " << t.value << std::endl;

        char stop;
        cout << "\nDeseja fazer outra conversão? (S/N): ";
        cin >> stop;

        if (stop == 'N' || stop == 'n')
        {
            cout << "Encerrando...\n";
            break;
        }
    }
    return 0;
}
