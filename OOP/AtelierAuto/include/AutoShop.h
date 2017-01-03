#ifndef AUTOSHOP_H
#define AUTOSHOP_H
#include<queue>

class Vehicle;

class AutoShop
{
    public:
        AutoShop();
        void DiagnoseVehicle(Vehicle *vehicle);
        float CalculateTotalCost(Vehicle *vehicle);
        void operator+=(Vehicle* vehicle);
        Vehicle* GetNext();
        void RemoveNext();
    protected:
    private:
        std::queue<Vehicle*> vehicleQueue;
};

#endif // AUTOSHOP_H
