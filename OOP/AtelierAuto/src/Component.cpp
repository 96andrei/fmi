#include "Component.h"
#include <iostream>
#include "Problem.h"

Component::Component()
{
    //ctor
}

Component::~Component(){
    //std::cout<<"Component dtor called";
}

void Component::PrintProblems(){
    PrintType();
    std::cout<<"\n";
    int count = 0;
    for(int i=0; i<problems.size(); i++){
        if(problems[i]->GetExisting() == false)
            continue;
        count++;
        std::cout<<"<<Problem "<<count<<">> ";
        problems[i]->PrintType();
        problems[i]->PrintRequiredMaterials();
        std::cout<<"Cost: "<<problems[i]->CalculatePrice()<<"\n";
    }
}

std::vector<Problem*> Component::GetProblems(){
    return problems;
}
