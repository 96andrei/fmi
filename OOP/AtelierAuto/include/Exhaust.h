#ifndef EXHAUST_H
#define EXHAUST_H

#include <Component.h>

class Vehicle;

class Exhaust : public Component
{
    public:
        Exhaust(Vehicle *attachedTo);
        ~Exhaust();
        void PrintType();
    protected:
    private:
};

#endif // EXHAUST_H
