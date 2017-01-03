#include "BurningOil.h"
#include <iostream>
#include "Oil.h"

BurningOil::BurningOil()
{
    costPerHour = 2.1f;
    requiredTime = 5;
    requiredMaterials.push_back(new Oil(2));
}

BurningOil::~BurningOil()
{
    //dtor
}

void BurningOil::PrintType(){
    std::cout<<"Burning Oil\n";
}
