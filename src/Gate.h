#ifndef GATE_H
#define GATE_H

#include "Contract.h"
#include <utility>
#include <vector>

class Gate{

    public:
        Gate(int ID);
        int getID();
        void newContract(Contract newContract);
        void changeContract(int contractID, Contract replacementContract);
        void occupationChange(bool occupation);
        
        std::vector<Contract>& gateContractCheck();
        
        bool isTheGateOccupied();
        bool doesTheGateHaveAContract();



    private:
        int ID;
        bool gateOccupied;
        bool gateHasContract; //TEMP UNTIL DYNAMIC SCHEDULEING
        std::vector<Contract> contracts;

};

#endif