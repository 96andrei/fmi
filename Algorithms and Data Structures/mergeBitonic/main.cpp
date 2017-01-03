#include <iostream>

using namespace std;

int auxiliary[100];

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

void mergeSort(int array[], int left, int right, int split, bool asc, int aux[] = auxiliary){

    if(right - left == 1)
        return;

    int mid = (left + right)/2;
    if(!(asc && mid <= split))
        mergeSort(array, left, mid, split, asc);
    if(!(!asc && mid >= split))
        mergeSort(array, mid, right, split, asc);
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

    bool asc = true;
    if(v[1]<v[0]){
        asc = false;
    }

    int split;
    for(int i=1; i<n; i++){
        if(asc){
            if(v[i]<v[i-1]){
                split = i;
                break;
            }
        }else{
           if(v[i]>v[i-1]){
                split = i;
                break;
            }
        }
    }

    mergeSort(v, 0, n, split, asc);

    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
    return 0;
}
