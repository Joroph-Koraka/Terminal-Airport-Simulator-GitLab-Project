#include <iostream>
#include <string>
#include "Menu.h"
#include "Runway.h"
using namespace std;

Runway::Runway(int number){

    if(number >= 360){
        number %= 360; //Makes sure that the number is within the 360 degree compass
    }

    runwayNumber = number;
    runwayName = to_string(number);
    string message = "Constructing Runway " + runwayName;
    // cout << "Runway " << runwayName << " has been built " << endl;
    loadingAnimation(message, 3, 350);

};


int Runway::IDcheck(){

    return runwayNumber;
}