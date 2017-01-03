#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int v[200000];
    string a;
    string b;
    cin>>a;
    cin>>b;
    int sum = 0;
    int left = 0, right = a.length()-1;

    if(a[0]!=b[0])
        v[0]=1;
    for(int i=1; i<b.length(); i++){
        v[i]=v[i-1];
        if(a[i%a.length()]!=b[i])
            v[i]++;
    }

    while(right < b.length()){
        sum+= fabs(v[right]-v[left]);
        left++;
        right++;
    }

    cout<<sum;

    return 0;
}
