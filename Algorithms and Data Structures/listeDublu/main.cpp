#include <iostream>

using namespace std;

struct nod{
    int info;
    nod *next;
    nod *prev;
};

void insertFirst(nod *&first, int n){
    nod *a = new nod;
    a->info=n;
    a->next = first;
    a->prev = NULL;
    if(first != NULL)
        first->prev = a;
    first = a;

}

void insertLast(nod *&first, int n){
    nod *a = first;
    if(a==NULL){
        a = new nod;
        a->info = n;
        a->next = NULL;
        a->prev = NULL;
        first = a;
        return;
    }

    while(a->next != NULL){
        a=a->next;
    }

    nod *b = new nod;
    b->info = n;
    b->prev = a;
    a->next = b;
    b->next = NULL;

}

void insertAt(nod *&first, int atPos, int n){
    if(atPos==1){
        insertFirst(first, n);
        return;
    }
    nod *a = first;
    int nr=1;
    while(nr<atPos){
        a = a->next;
        nr++;
    }
    if(a == NULL){
        insertLast(a, n);
        return;
    }
    nod *b = new nod;
    b->prev = a->prev;
    b->prev->next = b;
    b->info = n;
    b->next = a;
}

void showOrd(nod *a){
     while(a != NULL){
        cout<<a->info<<" ";
        a=a->next;
    }
    cout<<endl;
}

void showBackOrd(nod *a){
     while(a->next != NULL){
        a=a->next;
    }
    while(a != NULL){
        cout<<a->info<<" ";
        a=a->prev;
    }
    cout<<endl;
}

void deleteAt(nod *&first, int atPos){
    if(atPos==1){
        first->next->prev = NULL;
        nod *a = first->next;
        delete first;
        first = a;
        return;
    }
    nod *a = first;
    int nr=1;
    while(nr<atPos && a!= NULL){
        a = a->next;
        nr++;
    }
    if(a == NULL){
        return;
    }
    a->prev->next = a->next;
    if(a->next != NULL)
        a->next->prev = a->prev;
    delete a;
}


int main()
{
    nod *l = NULL;

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        //insertFirst(l, x);
        insertLast(l,x);
    }
    int x,y;
    cin>>x;
    deleteAt(l, x);
    //insertAt(l, y, x);
    showOrd(l);
    //showBackOrd(l);

    return 0;
}
