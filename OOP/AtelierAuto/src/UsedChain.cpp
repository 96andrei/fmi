#include "UsedChain.h"
#include <iostream>

UsedChain::UsedChain()
{
        costPerHour = 2;
        requiredTime = 1;
        //requiredMaterials.push_back(new Material);
}

UsedChain::~UsedChain()
{
    //dtor
}

void UsedChain::PrintType(){
    std::cout<<"Used Chain\n";
}
