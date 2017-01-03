#include <iostream>

using namespace std;

void insertion(int v[100], int left, int right){
    for(int i=left; i<right; i++){
        int j=i;
        while(v[j-1] > v[j] && j>left){
            int aux = v[j];
            v[j] = v[j-1];
            v[j-1] = aux;
            j--;
        }
    }
}

void qs(int v[100],int left,int right)
{
    if(right-left <= 11){
        insertion(v, left, right);
        return;
    }

    int piv;
    piv=v[left + (right-left)/2];
    int i,j;
    i=left;
    j=right-1;
    while(i <= j)
    {
        while(v[i] < piv)
            i++;
        while(v[j] > piv)
            j--;

        if(i <= j)
        {
            int aux=v[i];
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
    int n;
    int v[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    //int v[6]={0,3,1,4,5,2};
    qs(v,0,n);
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
    return 0;
}
