#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include "Vehicle.h"
#include "Motorbike.h"

class Material;

class Problem
{
    public:
        Problem();
        ~Problem();
        virtual float CalculatePrice();
        void PrintRequiredMaterials();
        virtual void PrintType()=0;
        bool GetExisting();
    protected:
        std::vector<Material*> requiredMaterials;
        float requiredTime;
        float costPerHour;
        bool existing = false;
    private:
        void SetActive();
        friend bool Vehicle::Traumatize(Problem *problem);
        friend Motorbike::Motorbike(const Motorbike &other);
};

#endif // PROBLEM_H
