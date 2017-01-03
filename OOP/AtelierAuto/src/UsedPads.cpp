#include "UsedPads.h"
#include <iostream>

UsedPads::UsedPads(bool front)
{
    this->front = front;
    if(front){
        //use some materials
    }else{
        //use more materials
    }

    costPerHour = 2;
    requiredTime = 3;
}

UsedPads::~UsedPads()
{
    //dtor
}

/*float UsedPads::CalculatePrice(){
    float materialCost = 0; //todo calculate it
    return requiredTime * costPerHour + materialCost;
}*/

void UsedPads::PrintType(){
    if(front)
        std::cout<<"Front Pads Broken\n";
    else
        std::cout<<"Rear Pads Broken\n";
}

