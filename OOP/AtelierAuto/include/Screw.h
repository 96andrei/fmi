#ifndef SCREW_H
#define SCREW_H

#include <Material.h>

class Screw : public Material
{
    public:
        Screw(int quantity);
        ~Screw();
        std::string GetName();
    protected:

    private:
};

#endif // SCREW_H
