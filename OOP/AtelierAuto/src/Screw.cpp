#include "Screw.h"
#include <iostream>

Screw::Screw(int quantity)
{
    usageCost = 3;
    this->quantity = quantity;
}

Screw::~Screw()
{
    //dtor
}

std::string Screw::GetName(){
    std::string s = "Screw";
    return s;
}
