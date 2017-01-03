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

void showOrd(nod *a){
     while(a != NULL){
        cout<<a->info<<" ";
        a=a->next;
    }
    cout<<endl;
}

void deleteFirst(nod *&first){
    if(first->next == NULL){
        delete first;
        first = NULL;
        return;
    }

    first->next->prev = NULL;
    nod *a = first->next;
    delete first;
    first = a;
    return;
}

void deleteLast(nod *&first){
    nod *a = first;
    while(a->next != NULL)
        a=a->next;
    if(a==first){
        delete a;
        first = NULL;
        return;
    }
    a->prev->next = NULL;
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

    deleteFirst(l);

    showOrd(l);

    return 0;
}
