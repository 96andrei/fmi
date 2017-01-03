#include <iostream>
#include <fstream>

using namespace std;

int k,n;
int v[16001];

bool check(long long int cap){
    long long int size = 0, i = 1;
    int steps = 0;
    while(steps <= k && i <= n){
        steps++;
        while(size + v[i] <= cap && i<=n){
            size+=v[i];
            i++;
        }
        size = 0;
    }
    if(steps <= k && i>=n)
        return true;
    return false;
}

long long int binary(){
    long long int step = 8589934592;
    long long int i, lastGood =0;
    for(i = 0; step != 0; step>>=1)
        if(check(i+step))
            lastGood = i+step;
        else
            i+=step;
    return lastGood;
}

int main()
{
    ifstream fin("transport.in");
    ofstream fout("transport.out");
    fin>>n>>k;
    for(int i=1; i<=n; i++)
        fin>>v[i];

    fout<<binary();

    return 0;
}
