#include "Contract.h"
#include "Menu.h"
#include "Terminal.h"
#include "Gate.h"
#include <iostream>
#include <iomanip>
#include <exception>
#include <memory>
#include <stdexcept>
#include <vector>
#include <utility>
#include "ContractManager.h"
#include "Contract.h"
using namespace std;


ContractManager::ContractManager(){

    Contract contract1("Southwest", 1, make_pair(5, 9), 150, 200);
    Contract contract2("Delta", 2, make_pair(8, 12), 300, 500);
    Contract contract3("JetBlue", 1, make_pair(13, 15), 100, 100);
    Contract contract4("United", 2, make_pair(16, 20), 200, 1000);
    Contract contract5("Alaska", 1, make_pair(21, 23), 75, 50);

    contracts.push_back(contract1);
    contracts.push_back(contract2);
    contracts.push_back(contract3);
    contracts.push_back(contract4);
    contracts.push_back(contract5);

    // cout << "Manager hired" << endl;
    loadingAnimation("Hiring Manager", 3, 350);

}

void ContractManager::displayAvailableContacts(){
    int i = 0;
    for(Contract& con : contracts){
        cout << "Index: " << i << " | " << con.grabAirline() << " flight# " << con.grabFlightNum() << " of type " << con.grabType() << " with " << con.grabSeats() << " seats of price $" 
            << con.grabTicketPrice() << " , arriving at hour " << con.grabSchedule().first << " and leaving at hour " << con.grabSchedule().second << endl;
        ++i;
    }

}

//Brings up the UI to prompt the user for where the new contract should go
void ContractManager::assignContract(vector<Terminal>& terminals){
    int terminalID, gateID, contractIndex;
    
    //Lists the terminals available
    cout << "Current Terminals: " << endl;
    /*for (Terminal term : terminals){
        cout << "    " << term.returnID() << "    " << term.returnName() << endl;
    }*/
    cout << left << setw(8) << "\nIndex" << setw(20) << " Terminal" << endl;
    cout << string(30, '-') << endl;

    for (Terminal term : terminals) {
        cout << setw(8) << term.returnID() << setw(20) << term.returnName() << endl;
    }

    cout << string(30, '-') << endl; // Closing separator


    cout << endl << "Which terminal would you like to assign the new contract to? (Select Index) ";
    cin >> terminalID;

    //Displays every gate and it's occupation in that terminal
    terminals.at(terminalID).displayGates();
    vector<Gate>& gates = terminals.at(terminalID).returnGates();

    cout << endl << "Which gate number do you want to assign a new contract to? ";
    cin >> gateID;
    cout << endl;

    //Checks if the gate already has a contract assigned to it | This is temporary, planned to have multiple contracts assigned to a single gate in the future
    try{
        if(gates.at(gateID).doesTheGateHaveAContract()){
            throw invalid_argument("That gate currently has a contract"); //TEMP
        }

        //If there is no other contract, normal assignment will occur
        displayAvailableContacts();
        cout << "\nWhich contract do you want to assign to Gate: " << gateID << "? (Select Index) ";
        cin >> contractIndex;
        cout << endl;

        gates.at(gateID).newContract(contracts.at(contractIndex));

    } catch (const invalid_argument& expt){
        
        //However, if there is a contract, replacement will occur, in the future, this may be more of a prompt asking if the user wants to replace, or add a new contract to the gate, with a schedule checker to make sure that the schedule does not overlap
        cout << expt.what() << ". Here is a list of them: " << endl;

        //Shows every contract that is attributed to the gate
        vector<Contract> gateContracts = gates.at(gateID).gateContractCheck();
        int i = 0;
        for(Contract con : gateContracts){
            cout << "Index: " << i << " | " << con.grabAirline() << " of type " << con.grabType() << " with " << con.grabSeats() << " seats of price $" 
                << con.grabTicketPrice() << " , arriving at hour " << con.grabSchedule().first << " and leaving at hour " << con.grabSchedule().second << endl;
            ++i;
        }

        cout << endl << "Which index do you want to replace? (-ve number to exit) ";
        int replaceIndex;
        cin >> replaceIndex;
        cout << endl;

        
        if(replaceIndex >= 0){
            displayAvailableContacts();
            cout << "Which contract index do you want to assign to Gate: " << gateID << "? ";
            cin >> contractIndex;
            cout << endl;

            gates.at(gateID).changeContract(replaceIndex, contracts.at(contractIndex));
        }


    }
    

}

