#include "OldVehicle.h"
#include <iostream>

OldVehicle::OldVehicle()
{
    costPerHour = 5;
    requiredTime = 25;
    //add mats
}

OldVehicle::~OldVehicle()
{
    //dtor
}

void OldVehicle::PrintType(){
    std::cout<<"Old Vehicle\n";
}
