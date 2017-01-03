#include "Vehicle.h"
#include "Problem.h"
#include "Component.h"
#include <vector>

Vehicle::Vehicle()
{
    //ctor
}

Vehicle::~Vehicle(){

}

bool Vehicle::Traumatize(Problem *problem){
    std::vector<Component*>  components = GetComponents();
    for(int i=0; i<components.size(); i++){
        std::vector<Problem*> problems = components[i]->GetProblems();
        for(int j=0; j<problems.size(); j++){
            if(problems[j] == problem){
                problems[j]->SetActive();
                return true;
            }
        }
    }
    return false;
}
