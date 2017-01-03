#include <iostream>

using namespace std;

struct nod{
    int info;
    nod *left, *right;
    int h;
    nod(int key){
        info = key;
        left = NULL;
        right = NULL;
        h = 0;
    }
    nod(){}
};

int height(nod *p){
    return p!=NULL ? p->h : 0;
}

int balFactor(nod *p){
    return height(p->right) - height(p->left);
}

void putHeight(nod *p){
    int hl = height(p->left);
    int hr = height(p->right);
    p->h = (hl>hr ? hl : hr) + 1;
}

nod* rotateRight(nod *p) {
    nod *q = p->left;
    p->left = q->right;
    q->right = p;
    putHeight(p);
    putHeight(q);
    return q;
}

nod* rotateLeft(nod *p){
    nod *q = p->right;
    p->right = q->left;
    q->left = p;
    putHeight(p);
    putHeight(q);
    return q;
}

nod* balance(nod *p){
	putHeight(p);
    if(balFactor(p) == 2){
        if(balFactor(p->right) < 0)
            p->right = rotateRight(p->right);
        return rotateLeft(p);
    }
    if(balFactor(p) == -2){
        if(balFactor(p->left) > 0)
            p->left = rotateLeft(p->left);
        return rotateRight(p);
    }
    return p;
}

nod* insert(nod *p, int key){
    if(p == NULL){
        return new nod(key);
    }
    if(key < p->info){
        p->left = insert(p->left, key);
    }
    if(key >= p->info){
        p->right = insert(p->right, key);
    }
    balance(p);
}

nod* findMin(nod* p)
{
    return p->left ? findMin(p->left) : p;
}

nod *removeMin(nod* p)
{
    if(p->left == 0)
        return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}

nod* remove(nod *p, int key){
    if(!p)
        return 0;
    if(key < p->info)
        p->left = remove(p->left, key);
    else if(key > p->info)
        p->right = remove(p->right, key);
    else {
        nod *q = p->left;
        nod *r = p->right;
        delete p;
        if(!r)
            return q;
        nod *min = findMin(r);
        min->right = removeMin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

void rsd(nod *p){
    cout<<p->info<<" ";
    if(p->left){
        rsd(p->left);
    }
    if(p->right){
        rsd(p->right);
    }
}

int main()
{
    nod *tree = NULL;
    int n, x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        tree = insert(tree, x);
    }

    rsd(tree);

    cin>>x;
    tree = remove(tree, x);
    rsd(tree);

    return 0;
}
