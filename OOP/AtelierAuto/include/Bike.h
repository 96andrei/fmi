#ifndef BIKE_H
#define BIKE_H

#include <Vehicle.h>

class Brakes;
class Direction;
class Exhaust;

class Bike : public Vehicle
{
    public:
        Bike();
        ~Bike();
        std::vector<Component*> GetComponents();
        void PrintType();
    protected:
    private:
        Brakes *chain;
        Direction *direction;
};

#endif // BIKE_H
