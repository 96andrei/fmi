#include <iostream>

using namespace std;

int auxiliary[100];

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

void merge(int a[], int left, int mid, int right, int b[]){
    int i0 = left, i1 = mid;
    for(int i=left; i<right; i++){
        if(i0 < mid && ((i1 >= right) || (a[i0] <= a[i1]))){
            b[i]=a[i0];
            i0++;
        }else{
            b[i]=a[i1];
            i1++;
        }
    }
}

void copy(int source[], int left, int right, int result[]){
    for(int i=left; i<right; i++){
        result[i] = source[i];
    }
}

void mergeSort(int array[], int left, int right, int aux[] = auxiliary){

    if(right - left < 10){
        insertion(array, left, right);
        return;
    }

    if(right - left == 1)
        return;

    int mid = (left + right)/2;
    mergeSort(array, left, mid, aux);
    mergeSort(array, mid, right, aux);
    merge(array, left, mid, right, aux);
    copy(aux, left, right, array);
}

int main()
{
    int n;
    int v[100];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    mergeSort(v, 0, n);

    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
    return 0;
}
