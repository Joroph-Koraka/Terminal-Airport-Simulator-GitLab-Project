#ifndef TERMINAL_H
#define TERMINAL_H

#include <vector>
#include <utility>
#include "Gate.h"

/*
Terminal Class

There are 5 types, all with varying max amount of upgrades they can hold. 

(#) is the int number that will be used to indicate what type the terminal object is

(0) Standard

(1) Deluxe

(2) Outboard

(3) High-Class

(4) Private
*/


class Terminal{

    public:
        Terminal(int type, int ID, std::string name);
        void upgradeService();
        void displayStatus();
        void displayGates();
        std::pair<int, int> updateGates(int time);

        int returnID();
        std::string returnName();
        std::vector<Gate>& returnGates();
        
    private:

    int terminalType; //Indicates what type this terminal object is
    int terminalID;
    std::string terminalName;

    int checkpoints;
    int restaurants;
    int bathrooms;
    int shops;

    int maxCheckpoints;
    int maxRestaurants;
    int maxBathrooms;
    int maxShops;
    int maxGates;

    std::vector<Gate> gates;


};

#endif