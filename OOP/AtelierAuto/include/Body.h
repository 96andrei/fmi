#ifndef BODY_H
#define BODY_H

#include <Component.h>


class Body : public Component
{
    public:
        Body(Vehicle *attachedTo);
        ~Body();
        void PrintType();
    protected:
    private:
};

#endif // BODY_H
