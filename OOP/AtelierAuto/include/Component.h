#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>

class Problem;
class Vehicle;

class Component
{
    public:
        Component();
        ~Component();
        virtual void PrintType()=0; //print to console main category type, needed something to make an abstract class
        void PrintProblems();
        std::vector<Problem*> GetProblems();
    protected:
        std::string typeString;
        Vehicle *attachedTo;  //1 - car, 2 - motorbike, 3 - bike
        std::vector<Problem*> problems;
    private:

};

#endif // COMPONENT_H
