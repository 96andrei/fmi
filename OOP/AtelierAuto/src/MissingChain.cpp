#include "MissingChain.h"
#include <iostream>

MissingChain::MissingChain()
{
    costPerHour = 1;
    requiredTime = 1;
    //requiredMaterials.push_back(new Material);
}

MissingChain::~MissingChain()
{
    //dtor
}

void MissingChain::PrintType(){
    std::cout<<"Missing Chain\n";
}
