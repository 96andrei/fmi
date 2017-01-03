#include <iostream>

using namespace std;

struct nod{
    int info;
    nod *next;
    nod *prev;
};

void insertFirst(nod *first, int n){
    nod *a = new nod;
    a->info=n;
    a->next = first->next;
    a->prev = first;
    first->next->prev = a;
    first->next = a;
}

void showOrd(nod *first){
    nod *a = first->next;

     while(a != first){
        cout<<a->info<<" ";
        a=a->next;
    }
    cout<<endl;
}

void deleteKey(nod *&first, int key){
    nod *a = first->next;
    while(a->info != key)
        a=a->next;
    a->prev->next = a->next;
    if(a->next != NULL)
        a->next->prev = a->prev;
    delete a;
}

void deleteRight(nod *&first){
    nod *a = first->prev;
    if(a==first)
        return;

    a->prev->next = a->next;
    first->prev = a->prev;
    delete a;
}

int main()
{
    nod *l = new nod;
    l->next = l;
    l->prev = l;

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        insertFirst(l,x);
    }

    deleteRight(l);

    showOrd(l);

    return 0;
}
