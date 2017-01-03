#include "Material.h"

Material::Material()
{
    //ctor
}

Material::~Material()
{
    //dtor
}

float Material::GetCostPerItem(){
    return usageCost;
}

float Material::GetTotalCost(){
    return quantity * usageCost;
}

int Material::GetQuantity(){
    return quantity;
}
