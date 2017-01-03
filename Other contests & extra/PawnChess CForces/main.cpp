#include <iostream>

using namespace std;

int distA[8];
int distB[8];

int main()
{
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            char c;
            cin>>c;
            if(c=='W'){
                if(distA[j] == 0)
                    distA[j]=i;
                else if(i < distA[j])
                    distA[j]=i;
            }
            else if(c=='B'){
                if(distB[j] == 0)
                    distB[j]=7-i;
                else if(7-i < distB[j])
                    distB[j]=7-i;
            }

        }
    }

    int minA=8, minB=8;
    for(int i=0; i<8; i++){
        if(distA[i] < minA && distA[i] != 0 && distB[i] == 0)
            minA = distA[i];
        if(distB[i] < minB && distB[i] != 0 && distA[i] == 0)
            minB = distB[i];
    }

    if(minA < minB)
        cout<<'A';
    else if(minB < minA)
        cout<<'B';
    else
        cout<<'A';

    return 0;
}
