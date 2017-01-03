#include "UsedDiscs.h"
#include <iostream>

UsedDiscs::UsedDiscs()
{
    costPerHour = 3;
    requiredTime = 4;
    //requiredMaterials.push_back(new Material);
}

UsedDiscs::~UsedDiscs()
{
    //dtor
}

/*
int UsedDiscs::CalculatePrice(){
    int materialCost = 0; //todo calculate it
    return requiredTime * costPerHour + materialCost;
}*/

void UsedDiscs::PrintType(){
    std::cout<<"Broken Disk\n";
}
