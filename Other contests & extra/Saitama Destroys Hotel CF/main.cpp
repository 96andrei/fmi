#include <iostream>

using namespace std;

struct pas{
    int f,t;
};

void qs(pas v[1000],int left,int right)
{
    int piv;
    piv=v[left + (right-left)/2].f;
    int i,j;
    i=left;
    j=right;
    while(i <= j)
    {
        while(v[i].f > piv)
            i++;
        while(v[j].f < piv)
            j--;

        if(i <= j)
        {
            pas aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            i++;
            j--;
        }
    }
    if(i < right)
        qs(v, i, right);
    if(left < j)
        qs(v, left, j);

}

int main()
{
    int n,s;
    pas v[1000];
    cin>>n>>s;
    for(int i=0; i<n; i++){
        int f,t;
        cin>>f>>t;
        v[i].f=f;
        v[i].t=t;
    }

    qs(v, 0, n-1);

    int time = 0;
    int i=0;
    while(s>0){
        while(v[i].f==s && i<n){
            if(v[i].t>time)
                time+=v[i].t - time;
            i++;
        }
        s--;
        time++;
    }

    cout<<time;

    return 0;
}
