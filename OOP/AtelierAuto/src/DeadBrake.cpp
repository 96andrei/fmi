#include "DeadBrake.h"
#include <iostream>

DeadBrake::DeadBrake()
{
        costPerHour = requiredTime = -1;
}

DeadBrake::~DeadBrake()
{
    //dtor
}

float DeadBrake::CalculatePrice(){
    return -1;
}

void DeadBrake::PrintType(){
    std::cout<<"Dead Brake\n";
}
