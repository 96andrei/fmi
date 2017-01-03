#include "RustedBody.h"
#include <iostream>

RustedBody::RustedBody()
{
    costPerHour = 1.5;
    requiredTime = 10;
    //add mats
}

RustedBody::~RustedBody()
{
    //dtor
}

void RustedBody::PrintType(){
    std::cout<<"Rusted Body\n";
}
