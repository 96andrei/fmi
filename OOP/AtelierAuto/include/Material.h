#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>

class Material
{
    public:
        Material();
        virtual ~Material();
        float GetCostPerItem();
        int GetQuantity();
        float GetTotalCost();
        virtual std::string GetName()=0;
    protected:
        int usageCost;
        int quantity;
    private:

};

#endif // MATERIAL_H
