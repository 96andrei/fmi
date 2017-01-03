#ifndef OIL_H
#define OIL_H

#include <Material.h>


class Oil : public Material
{
    public:
        Oil(int quantity);
        ~Oil();
        std::string GetName();
    protected:

    private:
};

#endif // OIL_H
