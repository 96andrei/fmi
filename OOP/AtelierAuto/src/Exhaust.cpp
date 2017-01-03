#include "Exhaust.h"
#include <iostream>
#include "BurningOil.h"
#include "OldVehicle.h"
#include "Car.h"
#include "Motorbike.h"

Exhaust::Exhaust(Vehicle *attachedTo)
{
    typeString = "~Exhaust~";
    this->attachedTo = attachedTo;
    if(dynamic_cast<Car*>(attachedTo) != NULL || dynamic_cast<Motorbike*>(attachedTo) != NULL){
        problems.push_back(new BurningOil());
        problems.push_back(new OldVehicle());
    }
}

Exhaust::~Exhaust()
{
    //std::cout<<"Exhaust dtor called";
    for(int i=0; i<problems.size(); i++)
        delete problems[i];
    problems.clear();
}

void Exhaust::PrintType(){
    std::cout<<typeString;
}
