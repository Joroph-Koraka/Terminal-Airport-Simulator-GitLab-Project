#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "Contract.h"
using namespace std;

Contract::Contract(string Airline, int planeType, std::pair<int,int> newSchedule, int seats, int ticketPrice){

    this-> planeType = planeType;
    airlineName = Airline;
    schedule = newSchedule;
    planeSeats = seats;
    this -> ticketPrice = ticketPrice;
    this -> flightNum = rand() % 10000;

}


pair<int,int> Contract::grabSchedule(){
    return schedule;
}

string Contract::grabAirline(){
    return airlineName;
}

int Contract::grabType(){
    return planeType;
}

int Contract::grabSeats(){
    return planeSeats;
}

int Contract::grabTicketPrice(){
    return ticketPrice;
}

int Contract::grabFlightNum(){
    return flightNum;
    
}