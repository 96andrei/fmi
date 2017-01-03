#include <iostream>

using namespace std;

void swap(int &x, int &y){
    int aux = x;
    x = y;
    y = aux;
}

void heapify(int v[], int place){
    int largest;
    int left = place * 2;
    int right = place * 2 + 1;
    if(left <= v[0] && v[left] > v[place])
        largest = left;
    else
        largest = place;
    if(right <= v[0] && v[right] > v[largest])
        largest = right;
    if(largest != place){
        swap(v[place], v[largest]);
        heapify(v, largest);
    }
}

void addToHeap(int v[], int key){
    v[v[0]] = key;
    if(v[0] > 1)
        heapify(v, v[0]/2);
}

void heapsort(int v[]){
    int n = v[0];
    for(int i=v[0]; i>=1; i--){
        swap(v[1], v[v[0]]);
        v[0]--;
        heapify(v, 1);
    }
    v[0]=n;
}

int main()
{
    int n;
    int v[100];
    cin>>n;
    v[0]=n;
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    for(int i=n/2; i>=1; i--){
        heapify(v, i);
    }

    heapsort(v);

    for(int i=1; i<=n; i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
