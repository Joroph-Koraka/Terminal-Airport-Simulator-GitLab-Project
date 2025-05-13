#include <iostream>
#include <iomanip>
#include "Terminal.h"
#include "Airport.h"
#include "Runway.h"
#include "ContractManager.h"
#include "Menu.h"
#include <stdexcept>
#include <thread>
#include <chrono>
#include <utility>
#include <string>
using namespace std;

Airport::Airport(std::string airportName){
    Terminal firstTerminal(0, 0, "Primary");
    loadingAnimation("Generating Airport", 3, 350);
    
    listOfTerminals.push_back(firstTerminal);

    time = 0;
    total_days = 0;
    passengers_day = 0;
    terminusDayTotal = 0;
    name = airportName;
    Terminus = 10000;

    Runway firstRunway(90);
    runways.push_back(firstRunway);

}

vector<Terminal>& Airport::returnTerminals(){

    return listOfTerminals;

}

void Airport::createNewTerminal(int type, string name){

    int newID = listOfTerminals.size(); //Finds the next ID number for the terminal
    Terminal newTerminal(type, newID, name);
    listOfTerminals.push_back(newTerminal);

}

void Airport::nextTurn(){

    for(int i = 0; i < 6; ++i){
        if (time == 23){
            time = 0;
            cout << endl << "-------------------------------------------------------------------------------" << endl
            << " NEW DAY! " << endl << " Day " << total_days << " stats: " << endl << " Total Terminus Earned: " << terminusDayTotal << endl << " Total Passengers: " << passengers_day << endl << endl;
            passengers_day = 0;   
            terminusDayTotal = 0;
            total_days += 1;
        } else {
            time += 1;
        }
        //Call contracts to update and generate income
        for (Terminal term : listOfTerminals){

            pair<int, int> totalBuffer = term.updateGates(time);
            Terminus += totalBuffer.first;
            terminusDayTotal += totalBuffer.first;
            passengers_day += totalBuffer.second;

        }

        //Call events function to determine if an event will happen or not
        cout << endl << "-------------------------------------------------------------------------------" << endl;
        cout << " Hour: " << time << endl << " Total Passengers: " << passengers_day << endl << " Day: " << total_days;
        cout << endl << "-------------------------------------------------------------------------------" << endl;
        if (i != 5){
            this_thread::sleep_for(chrono::seconds(5));
        }
    }

}

void Airport::upgradeAirport() {
    int userInput;
    int runwayNumbersInput;

    displayAirportUpgrades();
    cout << "What service do you want to upgrade (Select Index)? ";
    cin >> userInput;
    cout << endl;

    //Checks for correct user input and ensures that the maximum will not be exceeded
    if(userInput == 0 && !(runways.size() + 1 > 6)){
        try{
            displayRunways();
            cout << "\nWhat numbers should the runway have? " << "\nInsert here: ";
            cin >> runwayNumbersInput;
            cout << endl;
            
            //Ensures that there is no other runway with the number that was provided by the user
            for(Runway currentRunway :  runways){
                int ID;

                ID = currentRunway.IDcheck();

                if(ID == runwayNumbersInput){
                    throw invalid_argument("That number is already in use");
                }
            }

            //Builds the new runways
            Runway newRunway(runwayNumbersInput);
            runways.push_back(newRunway);
        } catch (invalid_argument& except){
            cout << except.what() << endl;
        }
  } else if (userInput == 1 && !(listOfTerminals.size() + 1 > 10)) {

    /*  int i = 0;

        cout << setw(5) << "Index" << setw(19) << "Terminal Type" << endl;

        cout << setw(5) << i << setw(25) << " Standard " << endl; i++;
        cout << setw(5) << i << setw(25) << " Deluxe " << endl; i++;
        cout << setw(5) << i << setw(25) << " Outboard " << endl; i++;
        cout << setw(5) << i << setw(25) << " High-class " << endl; i++;
        cout << setw(5) << i << setw(25) << " Private " << endl; i++;

        cout << "What type of terminal do you want? (-ve number to exit) ";
        cin >> userInput;
        if (userInput >= 0){
            cout << " What should the new terminal be called? ";
            
            string newTerminalName;
            cin >> newTerminalName;

            createNewTerminal(userInput, newTerminalName);
        }*/

        int i = 0;

        // Display header
        cout << setw(5) << "Index " << setw(19) << "Terminal Type" << endl;
        cout << string(35, '-') << endl; // Adds a separator for clarity

        // List terminal types
        cout << setw(5) << i << setw(25) << " Standard " << endl; i++;
        cout << setw(5) << i << setw(25) << " Deluxe " << endl; i++;
        cout << setw(5) << i << setw(25) << " Outboard " << endl; i++;
        cout << setw(5) << i << setw(25) << " High-class " << endl; i++;
        cout << setw(5) << i << setw(25) << " Private " << endl; i++;

        cout << string(35, '-') << endl; // Adds another separator

        // User input
        cout << "\nSelect which terminal you would like (-ve number to exit) ";
        cin >> userInput;
        cout << endl;

        if (userInput >= 0) {
            cout << "What should the new terminal be called? " << endl << "Insert here: ";

            string newTerminalName;
            cin.ignore();
            getline(cin, newTerminalName);
            cout << endl;

            createNewTerminal(userInput, newTerminalName);
        }
    
    } else {
        cout << "Invalid input | Outside of index range OR exceeded maximum allowed upgrades" << endl << endl;
    }

}

void Airport::displayAirportUpgrades(){

    /*int i = 0;

    cout << setw(5) << "Index" << setw(19) << "Upgrade" << endl;

    cout << setw(5) << i << setw(25) << " Runways " << runways.size() << "/" << 6 << endl; i++;
    cout << setw(5) << i << setw(25) << " Terminals " << listOfTerminals.size() << "/" << 10 << endl; i++; //Specific type limiting will be implemented later

    cout << endl;*/

        int i = 0;

    // Display header with a separator
    cout << left << setw(8) << "Index" << setw(19) << "Upgrade" << "Current / Max" << endl;
    cout << string(40, '-') << endl; // Adds a visual separator

    // Display airport upgrade data
    cout << left << setw(8) << i << setw(25) << "Runways" << runways.size() << " / " << 6 << endl; i++;
    cout << left << setw(8) << i << setw(25) << "Terminals" << listOfTerminals.size() << " / " << 10 << endl; i++;

    cout << endl;

}

void Airport::displayRunways(){

    cout << "Current Runways:" << endl;
    for(Runway currentRunway : runways){
            int ID;

            ID = currentRunway.IDcheck();

            cout << "Runway " << ID << endl;
        }

}

void Airport::assignNewContract(){

    manager.assignContract(listOfTerminals);

}

int Airport::returnTerminus(){
    return Terminus;
}