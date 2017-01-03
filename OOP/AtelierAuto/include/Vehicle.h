#ifndef VEHICLE_H
#define VEHICLE_H

#include<vector>

class Component;
class Problem;

class Vehicle
{
    public:
        Vehicle();
        virtual ~Vehicle();
        virtual std::vector<Component*> GetComponents()=0;
        virtual void PrintType()=0;
        bool Traumatize(Problem *problem);
    protected:
    private:
};

#endif // VEHICLE_H
