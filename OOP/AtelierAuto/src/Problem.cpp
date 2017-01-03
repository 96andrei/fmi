#include "Problem.h"
#include <iostream>
#include "Screw.h"

Problem::Problem()
{
    requiredMaterials.push_back(new Screw(5));
}

Problem::~Problem(){
    //std::cout<<"Problem dtor called";
    for(int i=0; i<requiredMaterials.size(); i++)
        delete requiredMaterials[i];
    requiredMaterials.clear();
}

void Problem::PrintRequiredMaterials(){
    std::cout<<"Materials:\n";
    for(int i=0; i<requiredMaterials.size(); i++)
        std::cout<<"-"<<requiredMaterials[i]->GetName()<<" * "<<requiredMaterials[i]->GetQuantity()<<"\n";
}

float Problem::CalculatePrice(){
    float materialCost = 0;
    for(int i=0; i<requiredMaterials.size(); i++)
        materialCost += requiredMaterials[i]->GetTotalCost();
    return requiredTime * costPerHour + materialCost;
}

void Problem::SetActive(){
    existing = true;
}

bool Problem::GetExisting(){
    return existing;
}
