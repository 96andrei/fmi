#ifndef BROKENBODY_H
#define BROKENBODY_H

#include <Problem.h>


class BrokenBody : public Problem
{
    public:
        BrokenBody();
        ~BrokenBody();
        float CalculatePrice();
        void PrintType();
    protected:
    private:
        int frontBumper, rearBumper;
        int leftBumper, rightBumper;
        int hood, spoiler;
};

#endif // BROKENBODY_H
