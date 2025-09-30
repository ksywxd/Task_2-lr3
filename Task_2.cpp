#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream> //для 'сканера' текста (string stream)

void checkInputChoice(int& choice) {
    while (true) {
        std::cout << "Start?\n1. YES\n2. EXIT\n3. show menu\n";
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cout << "Input error.\n";
            continue;
        }
        std::stringstream ss(line);
        if (ss >> choice && ss.eof()) {
            if (choice >= 1 && choice <= 3) {
                break; // одно число в диапазоне и ничего больше
            }
            else {
                std::cout << "Incorrect input. Enter 1, 2, or 3.\n";
            }
        }
        else {
            std::cout << "Incorrect input. Enter a single number.\n";
        }
    }
}

void Task() {
    const double eps = 1e-3;
    double sum = 0.0;
    int n = 1;
    double dn;

    do {
        dn = std::pow(2.0, -n) + std::pow(3.0, -n);
        if (dn >= eps) {
            sum += dn;
        }
        n++;
    } while (dn >= eps);

    std::cout << "Сумма ряда: " << sum << '\n';
}

void Menu() {
    std::cout << "\tTask 2\n";
    std::cout << "Находится сумма ряда с точностью до eps = 10^3, общий член которого dn = 1/2^n + 1/3^n\n";
    std::cout << "Creator: Kseniya Siamionava\n";
}

int main() {
    setlocale(LC_ALL, "RU");
    int choice = 0;

    while (true) {
        checkInputChoice(choice);

        if (choice == 1) {
            Task();
        }
        else if (choice == 2) {
            break;
        }
        else if (choice == 3) {
            Menu();
        }
    }

    return 0;
}