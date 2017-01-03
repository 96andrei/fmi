#include "Car.h"
#include "Problem.h"
#include "Brakes.h"
#include "Engine.h"
#include "Direction.h"
#include "Exhaust.h"
#include "Body.h"
#include "Component.h"
#include <iostream>

Car::Car()
{
    frontBrakes[0] = new Brakes(true, this);
    frontBrakes[1] = new Brakes(true, this);
    rearBrakes[0] = new Brakes(false, this);
    rearBrakes[1] = new Brakes(false, this);
    engine = new Engine(this);
    direction = new Direction(this);
    exhaust = new Exhaust(this);
    body = new Body(this);
}

Car::~Car(){
    delete[] frontBrakes;
    delete[] rearBrakes;
    delete engine;
    delete direction;
    delete exhaust;
    delete body;
}

std::vector<Component*> Car::GetComponents(){
    std::vector<Component*> components;
    components.push_back(frontBrakes[0]);
    components.push_back(frontBrakes[1]);
    components.push_back(rearBrakes[0]);
    components.push_back(rearBrakes[1]);
    components.push_back(engine);
    components.push_back(direction);
    components.push_back(exhaust);
    components.push_back(body);
    return components;
}

void Car::Traumatize(Problem *problem){

}

void Car::PrintType(){
    std::cout<<"=====Car=====\n";
}
