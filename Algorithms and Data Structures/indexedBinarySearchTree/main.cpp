#include <iostream>

using namespace std;

struct nod{
    int info;
    nod *left, *right;
    int leftSize;
    nod(int i, nod *l, nod *r){
        info = i;
        left = l;
        right = r;
        leftSize = 0;
    }
    nod(){}
};

void srd(nod *tree){
    if(tree == NULL)
        return;
    if(tree->left != NULL)
        srd(tree->left);
    cout<<tree->leftSize<<" ";
    if(tree->right != NULL)
        srd(tree->right);
}

void insert(nod *&tree, int key){
    if(tree == NULL){
        nod *a = new nod(key, NULL, NULL);
        tree = a;
        return;
    }

    if(key < tree->info){
        tree->leftSize++;
        if(tree->left == NULL){
            nod *a = new nod(key, NULL, NULL);
            tree->left = a;
        }else{
            insert(tree->left, key);
        }
    }else if(key > tree->info){
        if(tree->right == NULL){
            nod *a = new nod(key, NULL, NULL);
            tree->right = a;
        }else{
            insert(tree->right, key);
        }
    }

}

void showAtIndex(nod *tree, int index){
    if(tree->leftSize == index)
        cout<<tree->info<<endl;
    else if(tree->leftSize > index){
        showAtIndex(tree->left, index);
    }else{
        showAtIndex(tree->right, index - tree->leftSize-1);
    }
}

int main()
{
    nod *tree = NULL;
    int n, x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        insert(tree, x);
    }
    //srd(tree);
    cin>>x;
    showAtIndex(tree, x);

    return 0;
}
