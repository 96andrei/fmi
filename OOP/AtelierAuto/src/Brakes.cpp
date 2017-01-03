#include "Brakes.h"
#include <iostream>
#include "Problem.h"
#include "UsedPads.h"
#include "UsedDiscs.h"
#include "UsedChain.h"
#include "MissingChain.h"
#include "DeadBrake.h"
#include "Car.h"
#include "Motorbike.h"

Brakes::Brakes(bool front, Vehicle *attachedTo){
    typeString = "~Brakes~";
    this->front = front;
    this->attachedTo = attachedTo;


    if(dynamic_cast<Car*>(attachedTo) != NULL || dynamic_cast<Motorbike*>(attachedTo) != NULL){
        problems.push_back(new UsedPads(front));
        problems.push_back(new UsedDiscs());
    }else{
        problems.push_back(new UsedChain());
        problems.push_back(new MissingChain());
    }
    //problems.push_back(new DeadBrake());
}

Brakes::~Brakes()
{
    //std::cout<<"Brake dtor called";
    for(int i=0; i<problems.size(); i++)
        delete problems[i];
    problems.clear();
}

void Brakes::PrintType(){
    std::cout<<typeString;
}
