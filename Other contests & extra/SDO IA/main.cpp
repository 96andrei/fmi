#include <fstream>
#include <stdlib.h>

using namespace std;

int v[3000001];
int n,k;

void qs(int left,int right)
{
    if(left==right)
        return;

    int piv;
    piv=v[rand() % (right-left) + left];
    int i,j;
    i=left;
    j=right;
    while(i <= j)
    {
        while(v[i] < piv)
            i++;
        while(v[j] > piv)
            j--;

        if(i <= j)
        {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }

    if(i < right && k>=i)
        qs(i, right);
    if(left < j && k<=j)
        qs(left, j);
}

int main()
{
    ifstream fin("sdo.in");
    ofstream fout("sdo.out");

    fin>>n>>k;
    for(int i=1; i<=n; i++)
        fin>>v[i];

    qs(1, n);

    fout<<v[k];

    fin.close();
    fout.close();

    return 0;
}
