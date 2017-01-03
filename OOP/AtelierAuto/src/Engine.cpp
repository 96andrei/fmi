#include "Engine.h"
#include <iostream>
#include "LowOil.h"
#include "MoltenEngine.h"
#include "DirtyCarb.h"
#include "Car.h"
#include "Motorbike.h"

Engine::Engine(Vehicle *attachedTo)
{
    typeString = "~Engine~";
    this->attachedTo = attachedTo;

    if(dynamic_cast<Car*>(attachedTo) != NULL || dynamic_cast<Motorbike*>(attachedTo) != NULL){
        problems.push_back(new LowOil());
        problems.push_back(new MoltenEngine());
    }
    if(dynamic_cast<Car*>(attachedTo) != NULL){
        problems.push_back(new DirtyCarb());
    }

}

Engine::~Engine()
{
    //std::cout<<"Engine dtor called";
    for(int i=0; i<problems.size(); i++)
        delete problems[i];
}

void Engine::PrintType(){
    std::cout<<typeString;
}
