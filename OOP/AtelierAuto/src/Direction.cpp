#include "Direction.h"
#include <iostream>
#include "BrokenHandlebar.h"
#include "BrokenWheel.h"
#include "DeadDirection.h"
#include "Bike.h"
#include "Motorbike.h"
#include "Vehicle.h"

Direction::Direction(Vehicle *attachedTo)
{
    typeString = "~Direction~";
    this->attachedTo = attachedTo;
    if(dynamic_cast<Bike*>(attachedTo) != NULL || dynamic_cast<Motorbike*>(attachedTo) != NULL){
        problems.push_back(new BrokenHandlebar());
    }

    problems.push_back(new BrokenWheel());
    problems.push_back(new DeadDirection());
}

Direction::~Direction()
{
    //std::cout<<"Direction dtor called";
    for(int i=0; i<problems.size(); i++)
        delete problems[i];
}

void Direction::PrintType(){
    std::cout<<typeString;
}
