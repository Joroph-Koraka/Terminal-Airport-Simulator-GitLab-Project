#ifndef MENU_H
#define MENU_H

#include <string>

void displayStartScreen();
void clearScreen();
void loadingAnimation(const std::string& message, int dots, int delay);
void displayMenu(int Terminus);

#endif // MENU_H