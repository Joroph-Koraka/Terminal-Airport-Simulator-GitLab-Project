#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "Menu.h"

using namespace std;

void displayStartScreen() {
    cout << R"(
                             |
                             |
                             |
                           .-'-.
                          ' ___ '
                ---------'  .-.  '---------
_________________________'  '-'  '_________________________
 ''''''-|---|--/    \==][^',_m_,'^][==/    \--|---|-''''''
               \    /  ||/   H   \||  \    /
                '--'   OO   O|O   OO   '--'
         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            A I R P O R T    S I M U L A T O R
         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    )" << endl;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to create a loading effect
void loadingAnimation(const std::string& message, int dots, int delay) {
    for (int i = 0; i <= dots; i++) {
        std::cout << "\r" << message;
        for (int j = 0; j < i; j++) {
            std::cout << ".";
        }
        std::cout << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << std::endl;
}

void displayMenu(int Terminus) {
    cout << "\n";
    cout << "╔════════════════════════════╗\n";
    cout << "║        AIRPORT MENU        ║\n";
    cout << "╠════════════════════════════╣\n";
    cout << "║ 1. Upgrade Airport         ║\n";
    cout << "║ 2. Upgrade Terminals       ║\n";
    cout << "║ 3. New Contract            ║\n";
    cout << "║ 4. Next Move               ║\n";
    cout << "║ 5. Exit                    ║\n";
    cout << "╠════════════════════════════╣\n";
    cout << "║ Terminus Bank: $" << left << setw(11) << Terminus << "║\n";
    cout << "╚════════════════════════════╝\n";
    cout << "Select Option: ";
}

