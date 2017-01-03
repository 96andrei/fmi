#include <iostream>

using namespace std;

int popcnt(unsigned long long int n)
{
    return __builtin_popcount(n);
}

int main()
{
    unsigned long long int x, y;
    cin>>x>>y;

    int val = 0;
    for(;x<=y;x++){
        int count = 0;
        unsigned long long int k = x;
        while(k != 0){
            count++;
            k>>=1;
        }
        if(count - popcnt(x) == 1)
            val++;
    }

    cout<<val;

    return 0;
}
