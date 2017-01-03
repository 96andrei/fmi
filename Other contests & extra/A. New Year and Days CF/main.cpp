#include <iostream>

using namespace std;

//l-j,d 52
//v,s 53

int main()
{
    int x;
    string type;
    cin>>x;
    cin>>type>>type;
    if(type == "week"){
        if(x==5 || x == 6)
            cout<<53;
        else
            cout<<52;
    }
    else{
        if(x<=29)
            cout<<12;
        else if(x==30)
            cout<<11;
        else
            cout<<7;


    }

    return 0;
}
