#include <fstream>

using namespace std;

int lastgoodX;

int cauta(int a[], int n, long long b, int l, int r){
    int x = l + (r-l)/2;
    long long sum = 0;
    for(int i=0; i<n; i++){
        if(a[i]<x)
            sum+=a[i];
        else
            sum+=x;
    }

    if(sum<=b)
        lastgoodX = x;

    if(r - l <= 0 || sum==b)
        return x;

    if(sum < b)
        return cauta(a, n, b, x+1, r);
    else
        return cauta(a, n, b, l, x-1);
}

int main()
{
    ifstream fin("buget.in");
    ofstream fout("buget.out");
    int n,a[100000];
    long long b;
    int max = 0;
    fin>>n>>b;
    for(int i=0; i<n; i++){
        fin>>a[i];
        if(a[i]>max)
            max = a[i];
    }

    cauta(a,n,b,0,max);

    fout<<lastgoodX;

    return 0;
}
