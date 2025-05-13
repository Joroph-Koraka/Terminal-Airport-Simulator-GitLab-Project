#ifndef RUNWAY_H
#define RUNWAY_H

#include <string>
#include <vector>


//This is just a special upgrade that brings up attraction, future functionality would be limiting the amount of planes (and their types) that can arrive in an hour.

class Runway {

    public:
        Runway(int number);
        int IDcheck();


    private:
        std::string runwayName;
        int runwayNumber; //To make sure that no other runway has the same numberset

};


#endif
