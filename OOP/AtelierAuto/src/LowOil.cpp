#include "LowOil.h"
#include <iostream>
#include "Oil.h"

LowOil::LowOil()
{
    costPerHour = 1;
    requiredTime = 1;
    requiredMaterials.push_back(new Oil(1));
    //add mats
}

LowOil::~LowOil()
{
    //dtor
}

void LowOil::PrintType(){
    std::cout<<"Low Oil\n";
}
