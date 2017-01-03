#ifndef DEADDIRECTION_H
#define DEADDIRECTION_H

#include <Problem.h>


class DeadDirection : public Problem
{
    public:
        DeadDirection();
        ~DeadDirection();
        float CalculatePrice();
        void PrintType();
    protected:
    private:
};

#endif // DEADDIRECTION_H
