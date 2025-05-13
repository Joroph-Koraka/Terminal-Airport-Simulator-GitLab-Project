#ifndef CONTRACT_H
#define CONTRACT_H

#include <vector>
#include <string>
#include <utility>

class Contract{

    public:
        Contract(std::string Airline, int planeType, std::pair<int,int> schedule, int seats, int ticketPrice);
        std::pair<int,int> grabSchedule();
        std::string grabAirline();
        int grabType();
        int grabSeats();
        int grabTicketPrice();
        int grabFlightNum();
    
    private:
    std::string airlineName;
    int planeType;
    std::pair<int,int> schedule;
    int planeSeats;
    int ticketPrice;
    int flightNum;

};

#endif