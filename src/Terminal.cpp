#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include "Terminal.h"
#include "Contract.h"
#include "Gate.h"
#include "Menu.h"
using namespace std;


Terminal::Terminal(int type, int ID, string name){

    terminalType = type;
    terminalID = ID;
    terminalName = name;

    checkpoints = 1;
    restaurants = 1;
    bathrooms = 1;
    shops = 1;
    loadingAnimation("Spawning Terminal", 3, 350);

    if (terminalType == 0){

        maxCheckpoints = 3;
        maxRestaurants = 10;
        maxBathrooms = 4;
        maxShops = 10;
        maxGates = 6;

    }
    else if (terminalType == 1){

        maxCheckpoints = 5;
        maxRestaurants = 20;
        maxBathrooms = 8;
        maxShops = 15;
        maxGates = 14;

    }
    else if (terminalType == 2){

        maxCheckpoints = 2;
        maxRestaurants = 5;
        maxBathrooms = 4;
        maxShops = 2;
        maxGates = 8;

    }
    else if (terminalType == 3){

        maxCheckpoints = 1;
        maxRestaurants = 4;
        maxBathrooms = 2;
        maxShops = 2;
        maxGates = 4;

    }
    else if (terminalType == 4) {

        maxCheckpoints = 1;
        maxRestaurants = 2;
        maxBathrooms = 1;
        maxShops = 1;
        maxGates = 20;

    }
    else {
        cout << "TerminalType Error!";
    }

    Gate newGate(0);
    gates.push_back(newGate);

}

/*
Brings up a prompt asking the user what service they want to upgrade based on the index shown to them through displayStatus(). 
Then it takes that input and the input of how many times it should be upgraded, and then the function looks for that private values and updates it.
*/
void Terminal::upgradeService(){
    int userInput;
    int userAmount;

    displayStatus();
    cout << "What service do you want to upgrade? ";
    cin >> userInput;
    cout << "How many times do you want to upgrade? ";
    cin >> userAmount;
    cout << endl;

    //Takes the user input, checks to make sure that the userAmount is not going to cause the upgrade to exceed its maximum allowed value, and then adds the userAmount to the private variable
    if(userInput == 0 && !(checkpoints + userAmount > maxCheckpoints)){
        checkpoints += userAmount;
    } else if (userInput == 1 && !(restaurants + userAmount > maxRestaurants)){
        restaurants += userAmount;
    } else if (userInput == 2 && !(bathrooms + userAmount > maxBathrooms)){
        bathrooms += userAmount;
    } else if (userInput == 3 && !(shops + userAmount > maxShops)){
        shops += userAmount;
    } else if (userInput == 4 && !(gates.size() + userAmount > maxGates)){
        for (int i = 0; i < userAmount; ++i){
            Gate newGate(gates.size());
            gates.push_back(newGate);
        }
    } else {
        cout << "Invalid input | Outside of index range OR exceeded maximum allowed upgrades" << endl << endl;
    }
}

//Not quite sure how to do this better, but this just displays the upgrade private variables in a nice manner
/*void Terminal::displayStatus(){
    int i = 0;

    cout << setw(5) << "Index" << setw(19) << "Upgrade" << endl;

    cout << setw(5) << i << setw(25) << " Security Checkpoints " << checkpoints << "/" << maxCheckpoints << endl; i++;
    cout << setw(5) << i << setw(25) << " Restaurants " << restaurants << "/" << maxRestaurants << endl; i++;
    cout << setw(5) << i << setw(25) << " Bathrooms " << bathrooms << "/" << maxBathrooms << endl; i++;
    cout << setw(5) << i << setw(25) << " Commodity Shops " << shops << "/" << maxShops << endl; i++;
    cout << setw(5) << i << setw(25) << " Gates " << shops << "/" << maxGates << endl; i++;

    cout << endl <<"Gates Status: " << endl;
    
    displayGates();

    cout << endl;
}*/

void Terminal::displayStatus() {
    int i = 0;

    // Header with separator
    cout << left << setw(5) << "\nIndex" << setw(25) << "  Upgrade" << setw(12) << "Status" << endl;
    cout << string(45, '-') << endl;

    // Display upgrades with current/max values
    cout << setw(5) << i++ << setw(25) << "  Security Checkpoints" << checkpoints << "/" << maxCheckpoints << endl;
    cout << setw(5) << i++ << setw(25) << "  Restaurants" << restaurants << "/" << maxRestaurants << endl;
    cout << setw(5) << i++ << setw(25) << "  Bathrooms" << bathrooms << "/" << maxBathrooms << endl;
    cout << setw(5) << i++ << setw(25) << "  Commodity Shops" << shops << "/" << maxShops << endl;
    cout << setw(5) << i++ << setw(25) << "  Gates" << shops << "/" << maxGates << endl;

    cout << string(45, '-') << endl; // Closing separator

    // Display Gates Status
    cout << "\nGates Status:\n";
    displayGates();
    
    cout << endl;
}


void Terminal::displayGates(){

    for(Gate gate : gates){

        cout << "Gate: " << gate.getID() << " is ";
        if(gate.isTheGateOccupied()){
            cout << "occupied";
        } else {
            cout << "open";
        }

        if(gate.doesTheGateHaveAContract()){
            cout << " and is contracted " << endl;
        } else {
            cout << " and is NOT contracted " << endl;
        }

    }

}

pair<int, int> Terminal::updateGates(int time){
    int terminusTotal = 0;
    int passengersTotal = 0;

    for (Gate& gate : gates){

        vector<Contract>& gateContracts = gate.gateContractCheck();

        for (Contract& con : gateContracts){

            if(con.grabSchedule().first == time){

                gate.occupationChange(true);

                terminusTotal += con.grabTicketPrice() * con.grabSeats();
                passengersTotal += con.grabSeats(); //TEMP UNTIL DYNAMIC ATTRACTION
                cout << " " << terminalName << " Terminal Alert for Gate: " << gate.getID() << endl 
                << " " << con.grabAirline() <<" flight# " << con.grabFlightNum() << " has arrived and earned $" << con.grabTicketPrice() * con.grabSeats() << endl;

            } else if (con.grabSchedule().second == time){

                gate.occupationChange(false);

                terminusTotal += con.grabTicketPrice() * con.grabSeats();
                passengersTotal += con.grabSeats(); //TEMP UNTIL DYNAMIC ATTRACTION
                cout << " " << terminalName << " Terminal Alert for Gate: " << gate.getID() << endl 
                << " " << con.grabAirline() <<" flight# " << con.grabFlightNum()<< " has departed and earned $" << con.grabTicketPrice() * con.grabSeats() << endl;

            }

        }

    }

    return make_pair(terminusTotal, passengersTotal);

}


int Terminal::returnID(){
    return terminalID;
}

string Terminal::returnName(){
    return terminalName;
}

std::vector<Gate>& Terminal::returnGates(){
    return gates;
}