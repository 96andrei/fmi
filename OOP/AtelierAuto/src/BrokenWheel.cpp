#include "BrokenWheel.h"
#include <iostream>

BrokenWheel::BrokenWheel()
{
    costPerHour = 1.5f;
    requiredTime = 4;
    //requiredMaterials.push_back(new Material);
}

BrokenWheel::~BrokenWheel()
{
    //dtor
}

void BrokenWheel::PrintType(){
    std::cout<<"Broken Wheel\n";
}
