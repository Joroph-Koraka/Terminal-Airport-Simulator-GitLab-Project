#ifndef CONTRACTMANAGER_H
#define CONTRACTMANAGER_H

#include <vector>
#include <utility>
#include "Contract.h"
#include "Terminal.h"

class ContractManager{

    public:
        ContractManager();
        void displayAvailableContacts();
        void assignContract(std::vector<Terminal>& terminals);
        
    private:
        std::vector<Contract> contracts;

};





#endif