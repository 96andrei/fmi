#include <iostream>

using namespace std;

int main()
{
    int n;
    int v[200000];
    int b[200000];
    cin>>n;
    for(int i=0; i<n; i++){
        v[i]=0;
        cin>>b[i];
    }
    unsigned long long int steps = 0;
    int dif = 0;
    for(int i=0; i<n; i++){
        v[i]+=dif;
        dif += b[i]-v[i];
        if(v[i] != dif){
            steps += (dif>v[i]) ? dif - v[i] : v[i]-dif;
        }
        v[i]=dif;
    }

    cout<<steps;

    return 0;
}
