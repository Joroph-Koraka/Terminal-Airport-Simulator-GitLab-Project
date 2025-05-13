#ifndef AIRPORT_H
#define AIRPORT_H

#include <vector>
#include <string>
#include "ContractManager.h"
#include "Terminal.h"
#include "Runway.h"

class Airport{

    public:
        Airport(std::string airportName);
        void createNewTerminal(int type, std::string name);
        std::vector<Terminal>& returnTerminals();
        void nextTurn();
        void displayAirportUpgrades();
        void upgradeAirport();
        void displayRunways();
        void assignNewContract();

        int returnTerminus();

    private:

    std::vector<Terminal> listOfTerminals;
    std::string name;
    int time; // 0 - 23 representing the hours in the day that is being simulated
    int total_days;
    int passengers_day; //Amount of passengers that went to the airport in the day
    std::vector<Runway> runways;
    ContractManager manager;
    int Terminus; //Currency of the game
    int terminusDayTotal;

};

#endif