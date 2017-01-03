#include "Bike.h"
#include "Component.h"
#include <iostream>
#include <vector>
#include "Brakes.h"
#include "Direction.h"
#include "Exhaust.h"

Bike::Bike()
{
    chain = new Brakes(true, this);
    direction = new Direction(this);
}

Bike::~Bike()
{
        delete chain;
        delete direction;
}

std::vector<Component*> Bike::GetComponents(){
    std::vector<Component*> components;
    components.push_back(chain);
    components.push_back(direction);
    return components;
}

void Bike::PrintType(){
    std::cout<<"=====Bike=====\n";
}
