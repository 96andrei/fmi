#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include <Vehicle.h>

class Brakes;
class Direction;
class Exhaust;
class Engine;
class Body;

class Motorbike : public Vehicle
{
    public:
        Motorbike();
        ~Motorbike();
        Motorbike(const Motorbike &other);
        std::vector<Component*> GetComponents();
        void PrintType();
    protected:
    private:
        Brakes *frontBrakes;
        Brakes *rearBrakes;
        Engine *engine;
        Direction *direction;
        Exhaust *exhaust;
};

#endif // MOTORBIKE_H
