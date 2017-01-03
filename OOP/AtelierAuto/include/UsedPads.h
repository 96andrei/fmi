#ifndef USEDPADS_H
#define USEDPADS_H

#include <Problem.h>


class UsedPads : public Problem
{
    public:
        UsedPads(bool front);
        ~UsedPads();
        void PrintType();
    protected:
    private:
        bool front;
};

#endif // USEDPADS_H
