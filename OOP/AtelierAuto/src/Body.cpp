#include "Body.h"
#include <iostream>
#include "BrokenBody.h"
#include "RustedBody.h"
#include "Car.h"

Body::Body(Vehicle *attachedTo)
{
    this->attachedTo = attachedTo;
    typeString = "~Body~";
    if(dynamic_cast<Car*>(attachedTo) != NULL){
        problems.push_back(new BrokenBody());
        problems.push_back(new RustedBody());
    }
}

Body::~Body()
{
    //std::cout<<"Body dtor called";
    for(int i=0; i<problems.size(); i++)
        delete problems[i];
    problems.clear();
}

void Body::PrintType(){
    std::cout<<typeString;
}
