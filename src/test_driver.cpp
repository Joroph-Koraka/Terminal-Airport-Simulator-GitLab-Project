#include <stdexcept>
#include <string>
#include <iostream>
#include "ContractManager.h"
#include <vector>
#include <iomanip>
using namespace std;

#include "Airport.h" // references Airport class

int main() {
    string nameInput;

    cout << "What is the name of your airport? " << endl;
    cout << "Insert here: ";
    getline(cin, nameInput);

    Airport airport(nameInput);



    while(true){
        int userInput;
        cout << "Terminus Bank: $" << airport.returnTerminus() << endl << endl;
        cout << "Enter an action: " << endl;
        cout << "1: Upgrade airport" << endl;
        cout << "2: Upgrade terminals" << endl;
        cout << "3: New Contract" << endl;
        cout << "4: Next move" << endl;
        cout << "5: Quit" << endl;
        

        
        
        cin >> userInput;

        if(userInput == 1){
            airport.upgradeAirport();
        } else if (userInput == 2){
            int terminalID;

            vector<Terminal>& terminals = airport.returnTerminals();
    
            //Lists the terminals available
            cout << " Here is the list of terminals: " << endl;
            for (Terminal term : terminals){
                cout << "    " << term.returnID() << "    " << term.returnName() << endl;
            }

            cout << endl << " Which index number of terminal do you want to upgrade? ";
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
