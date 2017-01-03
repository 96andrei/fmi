#include <fstream>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int count = 0;
queue< pair<int,int> > q;

ifstream fin("egipt.in");
    ofstream fout("egipt.out");

void swap(int v[10000], int a, int b){
    int aux = v[a];
    v[a]=v[b];
    v[b]=aux;
    count++;
    q.push(make_pair(a+1, b+1));
}

int main()
{


    int n, v[10000];
    int one=0, two=0, three=0;

    fin>>n;
    for(int i=0; i<n; i++){
        fin>>v[i];
        if(v[i]==1)
            one++;
        else if(v[i]==2)
            two++;
        else
            three++;
    }

    int i1=0, i2=one, i3=one+two;
    while(v[i2]!= 1 && i2<one+two){
        i2++;
    }
    while(v[i3]!= 1 && i3<n){
        i3++;
    }
    while(i1 < one){
        if(v[i1] != 1){
            if(v[i1]== 3 && i3 < n){
                swap(v, i1, i3);
                do{
                    i3++;
                }while(v[i3]!=1 && i3<n);
            }else{
                if(i2<one+two){
                    swap(v, i1, i2);
                    do{
                        i2++;
                    }while(v[i2]!=1 && i2<one+two);
                }else{
                    swap(v, i1, i3);
                    do{
                        i3++;
                    }while(v[i3]!=1 && i3<n);
                }
            }
        }
        i1++;
    }

    i2=one; i3=one+two;

    while(v[i3]==3 && i3<n){
        i3++;
    }

    while(i2 < one+two){
        if(v[i2] != 2){
            swap(v, i2, i3);
            do{
                i3++;
            }while(v[i3]!=2 && i3<n);
        }
        i2++;
    }

    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";

    fout<<count<<endl;
    while(q.size()>0){
        fout<<q.front().first<<" "<<q.front().second<<endl;
        q.pop();
    }

    return 0;
}
