#include "AutoShop.h"
#include "Component.h"
#include "Vehicle.h"
#include "Problem.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include "Car.h"
#include "Motorbike.h"
#include "Bike.h"

AutoShop::AutoShop()
{
    //ctor
}

void AutoShop::DiagnoseVehicle(Vehicle *vehicle){
    vehicle->PrintType();

    std::vector<Component*> comps;

    comps = vehicle->GetComponents();
    for(int i=0; i<comps.size(); i++){
        comps[i]->PrintProblems();
        std:: cout<<"\n";
    }

    std::cout<<"============================\n";
}

float AutoShop::CalculateTotalCost(Vehicle *vehicle){
    float cost = 0;
    std::vector<Component*> comps;

    comps = vehicle->GetComponents();
    for(int i=0; i<comps.size(); i++){
        std::vector<Problem*> problems = comps[i]->GetProblems();
        for(int j=0; j<problems.size(); j++){
            if(problems[j]->GetExisting())
                cost += problems[j]->CalculatePrice();
        }
    }
    return cost;
}

void AutoShop::operator+=(Vehicle* vehicle){
    vehicleQueue.push(vehicle);
}

Vehicle* AutoShop::GetNext(){
    if(vehicleQueue.size()==0)
        throw 0;
    return vehicleQueue.front();
    /*try{
        if(vehicleQueue.size()==0)
            throw 0;
        return vehicleQueue.front();
    }catch(...){
        std::cout<<"Empty Queue";
        return NULL;
    }*/
}

void AutoShop::RemoveNext(){
    if(vehicleQueue.size() == 0)
            throw 0;
    if(typeid(*vehicleQueue.front()) == typeid(Car))
        std::cout<<"Removed Car";
    if(typeid(*vehicleQueue.front()) == typeid(Motorbike))
        std::cout<<"Removed Motorbike";
        if(typeid(*vehicleQueue.front()) == typeid(Bike))
        std::cout<<"Removed Bike";
    //std::cout<<"Removed "<<typeid(*vehicleQueue.front()).name()<<"\n\n\n";
    vehicleQueue.pop();
    /*try{
        if(vehicleQueue.size() == 0)
            throw 0;
        std::cout<<"Removed "<<typeid(*vehicleQueue.front()).name()<<"\n\n\n";
        vehicleQueue.pop();
    }catch(...){
        std::cout<<"Queue Already Empty\n";
    }*/
}
