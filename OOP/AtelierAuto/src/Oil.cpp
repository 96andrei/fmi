#include "Oil.h"
#include <string.h>

Oil::Oil(int quantity)
{
    this->quantity = quantity;
    usageCost = 5;
}

Oil::~Oil()
{
    //dtor
}

std::string Oil::GetName(){
    std::string s = "Oil";
    return s;
}
