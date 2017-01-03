#include "BrokenHandlebar.h"
#include <iostream>

BrokenHandlebar::BrokenHandlebar()
{
    costPerHour = 1.2f;
    requiredTime = 3;
    //requiredMaterials.push_back(new Material);
}

BrokenHandlebar::~BrokenHandlebar()
{
    //dtor
}

void BrokenHandlebar::PrintType(){
    std::cout<<"Broken Handle Bar\n";
}
