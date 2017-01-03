#include "MoltenEngine.h"
#include <iostream>
#include "Oil.h"

MoltenEngine::MoltenEngine()
{
    costPerHour = 5;
    requiredTime = 10;
    requiredMaterials.push_back(new Oil(3));
}

MoltenEngine::~MoltenEngine()
{
    //dtor
}

void MoltenEngine::PrintType(){
    std::cout<<"Molten Engine\n";
}
