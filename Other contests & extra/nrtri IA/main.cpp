#include <fstream>
#include <algorithm>

using namespace std;

int binary_search(int v[], int val, int n)
{
    int i;
    int step = 1;
    while(step<n)
        step<<=1;
    for (i = 0; step; step >>= 1)
        if (i + step < n && v[i + step] <= val)
           i += step;
    return i;
}

int main()
{
    ifstream fin("nrtri.in");
    ofstream fout("nrtri.out");
    int v[800];
    int n;
    fin>>n;
    for(int i=0; i<n; i++)
        fin>>v[i];

    sort(v, v+n);

    int nrtri = 0;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            nrtri+= binary_search(v, v[i]+v[j], n) - j;
        }
    }
    fout<<nrtri;

    return 0;
}
