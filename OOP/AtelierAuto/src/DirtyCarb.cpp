#include "DirtyCarb.h"
#include <iostream>

DirtyCarb::DirtyCarb()
{
    costPerHour = 1;
    requiredTime = 1;
    //add mats
}

DirtyCarb::~DirtyCarb()
{
    //dtor
}

void DirtyCarb::PrintType(){
    std::cout<<"Dirty Carb\n";
}
