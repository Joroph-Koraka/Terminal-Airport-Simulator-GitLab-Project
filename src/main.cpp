#include <stdexcept>
#include <string>
#include <iostream>
#include "ContractManager.h"
#include <vector>
#include <iomanip>
#include <sstream>
#include <thread>
#include <chrono>
using namespace std;

#include "Airport.h" // references Airport class
#include "Menu.h" // references Menu

int main() {
    displayStartScreen();

    cout << "\nPress Enter to Start...\n";
    cin.get();
    
    cout << "Welcome to Airport Simulator!" << endl;
    this_thread::sleep_for(chrono::milliseconds(750));

    string nameInput;

    cout << "\nWhat is the name of your airport? " << endl;
    this_thread::sleep_for(chrono::milliseconds(750));
    cout << "Insert here: ";
    getline(cin, nameInput);
    cout << endl;

    Airport airport(nameInput);

    while(true){
        int userInput;
        
        loadingAnimation("Initializing Terminus Bank", 3, 350);
        // cout << "Terminus Bank: $" << airport.returnTerminus() << endl << endl;
        loadingAnimation("Loading Menu", 3, 350);
        displayMenu(airport.returnTerminus());
        
        cin >> userInput;
        cout << endl;

        if(userInput == 1){
            airport.upgradeAirport();
        } else if (userInput == 2){
            int terminalID;

            vector<Terminal>& terminals = airport.returnTerminals();
    
            //Lists the terminals available
            cout << "Current Terminals: " << endl;
          /*for (Terminal term : terminals){
                cout << "    " << term.returnID() << "    " << term.returnName() << endl;
            }*/
            // Display terminal list as a table
            cout << left << setw(8) << "\nIndex" << setw(20) << "Terminal Name" << endl;
            cout << string(30, '-') << endl;

            for (Terminal term : terminals) {
                cout << setw(8) << term.returnID() << setw(20) << term.returnName() << endl;
            }

            cout << string(30, '-') << endl; // Closing separator


            cout << endl << "Choose terminal to upgrade (select index): ";
            cin >> terminalID;

            //Displays every gate and it's occupation in that terminal
            terminals.at(terminalID).upgradeService();

        } else if (userInput == 3){
            airport.assignNewContract(); 
        } else if (userInput == 4){
            airport.nextTurn();
        } else if (userInput == 5){
            break;
        }

    }


    return 0;
}
