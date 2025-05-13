#include <iostream>
#include <iomanip>
#include "Gate.h"
#include "Menu.h"
using namespace std;

Gate::Gate(int ID){
    this -> ID = ID;
    loadingAnimation("Creating Gate", 3, 350);
    gateOccupied = false;
    gateHasContract = false;

}


int Gate::getID(){
    return ID;
}

bool Gate::isTheGateOccupied(){
    return gateOccupied;
}

bool Gate::doesTheGateHaveAContract(){
    return gateHasContract;
}

void Gate::newContract(Contract newContract){

    contracts.push_back(newContract);
    cout << "NEW CONTRACT!\n" << endl;
    gateHasContract = true; //TEMPORARY UNTIL DYNAMIC SCHEDULE IS IMPLEMENTED

}

void Gate::occupationChange(bool occupation){

    gateOccupied = occupation;

}

void Gate::changeContract(int contractID, Contract replacementContract){

    contracts.at(contractID) = replacementContract;
    cout << "CONTRACT REPLACED!\n" << endl;

}

vector<Contract>& Gate::gateContractCheck(){

    return contracts;

}