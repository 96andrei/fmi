#include <iostream>

using namespace std;

int main()
{
    int a[200000],n;
    unsigned long long count = 0;
    int minpos;
    cin>>n;
    minpos = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]<=a[minpos]){
            minpos=i;
        }
    }
    unsigned long long val = a[minpos];
    int j, i, starting, secv,secvmax;
    starting = j = minpos+1;
    if(starting == n)
        starting = j = 0;
    i = j;
    secv = secvmax = 0;
    while(j!=minpos){
        if(a[j]==val){
            j++;
            starting = j;
            secv = 0;
            continue;
        }
        secv++;
        if(secv>secvmax){
            secvmax=secv;
            i = starting;
        }
        j++;
        if(j==n)
            j=0;
    }

    count += n*val;

    while(a[i] != val){
        count++;
        i++;
        if(i==n)
            i=0;
    }
    cout<<count;

    return 0;
}
