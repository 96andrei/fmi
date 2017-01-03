#include "Motorbike.h"
#include "Brakes.h"
#include "Engine.h"
#include "Direction.h"
#include "Exhaust.h"
#include <iostream>
#include <vector>
#include "Problem.h"

Motorbike::Motorbike()
{
    frontBrakes = new Brakes(true, this);
    rearBrakes = new Brakes(false, this);
    engine = new Engine(this);
    direction = new Direction(this);
    exhaust = new Exhaust(this);
}

Motorbike::~Motorbike()
{
    delete frontBrakes;
    delete rearBrakes;
    delete engine;
    delete direction;
    delete exhaust;
}

Motorbike::Motorbike(const Motorbike &other){
    frontBrakes = new Brakes(true, this);
    rearBrakes = new Brakes(false, this);
    engine = new Engine(this);
    direction = new Direction(this);
    exhaust = new Exhaust(this);

    std::vector<Problem*> otherProblems = other.frontBrakes->GetProblems();
    std::vector<Problem*> problems = frontBrakes->GetProblems();
    for(int i=0; i<problems.size(); i++){
        problems[i]->existing = otherProblems[i]->GetExisting();
    }

    otherProblems = other.rearBrakes->GetProblems();
    problems = rearBrakes->GetProblems();
     for(int i=0; i<problems.size(); i++){
        problems[i]->existing = otherProblems[i]->GetExisting();
    }

    otherProblems = other.engine->GetProblems();
    problems = engine->GetProblems();
     for(int i=0; i<problems.size(); i++){
        problems[i]->existing = otherProblems[i]->GetExisting();
    }

    otherProblems = other.direction->GetProblems();
    problems = direction->GetProblems();
     for(int i=0; i<problems.size(); i++){
        problems[i]->existing = otherProblems[i]->GetExisting();
    }

    otherProblems = other.exhaust->GetProblems();
    problems = exhaust->GetProblems();
     for(int i=0; i<problems.size(); i++){
        problems[i]->existing = otherProblems[i]->GetExisting();
    }
}

std::vector<Component*> Motorbike::GetComponents(){
    std::vector<Component*> components;
    components.push_back(frontBrakes);
    components.push_back(rearBrakes);
    components.push_back(engine);
    components.push_back(direction);
    components.push_back(exhaust);
    return components;
}

void Motorbike::PrintType(){
    std::cout<<"=====Motorbike=====\n";
}
