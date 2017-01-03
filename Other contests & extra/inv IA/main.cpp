#include <fstream>
#include <iostream>

using namespace std;

int inv = 0;

void merge(int a[], int left, int mid, int right, int b[]){
    int i0 = left, i1 = mid;
    for(int i=left; i<right; i++){
        if(i0 < mid && ((i1 >= right) || (a[i0] <= a[i1]))){
            b[i]=a[i0];
            i0++;
        }else{
            if(a[i1] < a[i0]){
                inv+=mid-i0;
                if(inv>=9917){
                    inv%=9917;
                }
            }
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

void mergeSort(int array[], int left, int right, int aux[]){

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
    ifstream fin("inv.in");
    ofstream fout("inv.out");
    int v[100000], n, b[100000];
    fin>>n;
    for(int i=0; i<n; i++)
        fin>>v[i];

    mergeSort(v, 0, n, b);

    fout<<inv;
    return 0;
}
