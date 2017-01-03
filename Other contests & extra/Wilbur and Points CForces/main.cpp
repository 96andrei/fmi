#include <iostream>

using namespace std;


int x[100001], y[100001];

void qs(int left,int right)
{
    int piv;
    piv=x[ left + (right-left)/2];
    int i,j;
    i=left;
    j=right;
    while(i <= j)
    {
        while(x[i] < piv)
            i++;
        while(x[j] > piv)
            j--;

        if(i <= j)
        {
            int aux=x[i];
            x[i]=x[j];
            x[j]=aux;
            aux = y[i];
            y[i]=y[j];
            y[j]=aux;
            i++;
            j--;
        }
    }
    if(i < right)
     {
         qs(i, right);
     }
    if(left < j)
     {
         qs(left, j);
     }

}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>x[i]>>y[i];

    qs(1,n);

    for(int i=1; i<=n; i++)
        cout<<x[i]<<" "<<y[i]<<endl;
    return 0;
}
