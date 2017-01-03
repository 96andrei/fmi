#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Brakes;
class Direction;
class Exhaust;
class Engine;
class Body;
class Problem;

class Car : public Vehicle
{
    public:
        Car();
        ~Car();
        std::vector<Component*> GetComponents();
        void PrintType();
        void Traumatize(Problem *problem);
    protected:
    private:
        Brakes *frontBrakes[2];
        Brakes *rearBrakes[2];
        Engine *engine;
        Direction *direction;
        Exhaust *exhaust;
        Body *body;

};


#endif // CAR_H
