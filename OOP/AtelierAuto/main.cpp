#include <iostream>
#include "AutoShop.h"
#include "Car.h"
#include "Bike.h"
#include "Motorbike.h"
#include <vector>
#include "Component.h"
#include "Problem.h"

using namespace std;

int main()
{
    AutoShop shop;
    //shop.DiagnoseVehicle(new Motorbike());
    //shop.DiagnoseVehicle(new Car());
    //shop.DiagnoseVehicle(new Bike());
    shop+=new Motorbike();
    Vehicle *myVehicle;
    myVehicle = shop.GetNext();
    //cout<<shop.CalculateTotalCost(shop.GetNext())<<"\n";

    shop.DiagnoseVehicle(myVehicle);
    cout<<"Total Cost: "<<shop.CalculateTotalCost(myVehicle)<<"\n";

    int inputI = 0, inputJ = 0;
    vector<Component*> components = myVehicle->GetComponents();
    while(inputI != -1){
        cout<<"Traumatize Menu\n";
        for(int i=0; i<components.size(); i++){
            cout<<i<<" : ";
            components[i]->PrintType();
            cout<<"\n";
            vector<Problem*> problems = components[i]->GetProblems();
            for(int j=0; j<problems.size(); j++){
                if(problems[j]->GetExisting())
                    continue;
                cout<<" "<<j<<" : ";
                problems[j]->PrintType();
            }
        }
        cin>>inputI;
        if(inputI == -1)
            break;
        cin>>inputJ;

        myVehicle->Traumatize(myVehicle->GetComponents()[inputI]->GetProblems()[inputJ]);
    }

    cout<<"\n";

    shop.DiagnoseVehicle(myVehicle);

    Motorbike newBike = *(Motorbike*)myVehicle;

    cout<<"Total Cost: "<<shop.CalculateTotalCost(myVehicle)<<"\n";

    shop.RemoveNext();
    delete myVehicle;

    cout<<"\n\nNew Copied Bike\n\n";
    shop.DiagnoseVehicle(&newBike);
    cout<<"Total Cost: "<<shop.CalculateTotalCost(&newBike)<<"\n";


    /*shop.RemoveNext();

    try{
        shop.RemoveNext();
    }catch(...){
        cout<<"Empty";
    }*/
    return 0;
}
