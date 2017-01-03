#include "DeadDirection.h"
#include <iostream>

DeadDirection::DeadDirection()
{
    costPerHour = -1;
    requiredTime = -1;
}

DeadDirection::~DeadDirection()
{
    //dtor
}

float DeadDirection::CalculatePrice(){
    return -1;
}

void DeadDirection::PrintType(){
    std::cout<<"Dead Direction\n";
}
