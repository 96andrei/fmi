#ifndef ENGINE_H
#define ENGINE_H

#include <Component.h>

class Vehicle;

class Engine : public Component
{
    public:
        Engine(Vehicle *attachedTo);
        ~Engine();
        void PrintType();
    protected:
    private:
};

#endif // ENGINE_H
