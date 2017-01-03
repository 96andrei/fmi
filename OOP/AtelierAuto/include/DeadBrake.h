#ifndef DEADBRAKE_H
#define DEADBRAKE_H

#include <Problem.h>


class DeadBrake : public Problem
{
    public:
        DeadBrake();
        ~DeadBrake();
        float CalculatePrice();
        void PrintType();
    protected:
    private:
};

#endif // DEADBRAKE_H
