#ifndef DIRECTION_H
#define DIRECTION_H

#include <Component.h>

class Vehicle;

class Direction : public Component
{
    public:
        Direction(Vehicle *attachedTo);
        ~Direction();
        void PrintType();
    protected:
    private:
};

#endif // DIRECTION_H
