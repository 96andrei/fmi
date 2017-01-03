#include "BrokenBody.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <Material.h>

BrokenBody::BrokenBody()
{
    costPerHour = 1.2;
    requiredTime = 2;
    //add mats

    //randomize each part state
    srand(time(NULL));
    int const mod = 4;
    frontBumper = rand() % mod;
    rearBumper = rand() % mod;
    leftBumper = rand() % mod;
    rightBumper = rand() % mod;
    hood = rand() % mod;
    spoiler = rand() % mod;
}

BrokenBody::~BrokenBody()
{
    //dtor
}

float BrokenBody::CalculatePrice(){
    float materialCost = 0;
    //TODO go through materials

    float piecesCost = 0;
    piecesCost += frontBumper * costPerHour * requiredTime;
    piecesCost += rearBumper * costPerHour * requiredTime;
    piecesCost += leftBumper * costPerHour * requiredTime;
    piecesCost += rightBumper * costPerHour * requiredTime;
    piecesCost += hood * costPerHour * requiredTime;
    piecesCost += spoiler * costPerHour * requiredTime;

    for(int i=0; i<requiredMaterials.size(); i++){
        materialCost += requiredMaterials[i]->GetTotalCost();
    }

    return piecesCost + materialCost;
}

void BrokenBody::PrintType(){
    std::cout<<"Broken Body\n";
    std::string s[3] = {"easy damaged\n", "partly damaged\n", "heavy damaged\n"};
    if(frontBumper)
        std::cout<<" -Front bumper "<<s[frontBumper-1];
    if(rearBumper)
        std::cout<<" -Rear bumper "<<s[rearBumper-1];
    if(leftBumper)
        std::cout<<" -Left bumper "<<s[leftBumper-1];
    if(rightBumper)
        std::cout<<" -Right bumper "<<s[rightBumper-1];
    if(hood)
        std::cout<<" -Hood "<<s[hood-1];
    if(spoiler)
        std::cout<<" -Spoiler "<<s[spoiler-1];
}
