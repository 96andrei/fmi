#ifndef BRAKES_H
#define BRAKES_H

#include "Component.h"

class Brakes : public Component
{
    public:
        Brakes(bool front, Vehicle *attachedTo);
        ~Brakes();
        void PrintType();
    protected:
    private:
        bool front; // 1 - front, 0 - rear
};

#endif // BRAKES_H
