#include <iostream>

using namespace std;

struct nod{
    int info;
    int priority;
    nod *next;
};

void insert(nod *&cap, int key, int priority){
    if(cap == NULL){
        nod *a = new nod;
        a->info = key;
        a->priority = priority;
        a->next = NULL;
        cap = a;
        return;
    }

    if(priority < cap->priority){
        nod *a = new nod;
        a->info = key;
        a->priority = priority;
        a->next = cap;
        cap = a;
        return;
    }

    nod *a = cap;
    while(a->next != NULL && a->next->priority <= priority){
        a=a->next;
    }
    nod *b = new nod;
    b->info = key;
    b->priority = priority;
    b->next = a->next;
    a->next = b;
}

void remove(nod *&cap){
    nod *a = cap;
    cap = cap->next;
    delete a;
}

void show(nod *cap){
    nod *a = cap;
    while(a!=NULL){
        cout<<a->info<<" ";
        a = a->next;
    }
}

int main()
{
    nod *cap = NULL;

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x,p;
        cin>>x>>p;
        insert(cap, x, p);
    }

    remove(cap);

    show(cap);

    return 0;
}
