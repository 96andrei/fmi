#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int n;
int b[250][250];
struct nod{
    int x,y,d;
};
queue<nod> q;

bool isInBounds(int x, int y){
    return x>=0 && y>=0 && x<n && y<n && b[x][y]!=-2;
}

void bfs(int x, int y, int d){
    if(b[x][y] > d || b[x][y]==-1)
        b[x][y]=d;
    else
        return;
    nod a;
    a.d = d+1;
    if(isInBounds(x+1,y)){
        if(b[x+1][y]>b[x][y]+1 || b[x+1][y]==-1){
            a.x = x+1;
            a.y = y;
            q.push(a);
        }
    }
    if(isInBounds(x,y+1)){
        if(b[x][y+1]>b[x][y]+1 || b[x][y+1]==-1){
            a.x = x;
            a.y = y+1;
            q.push(a);
        }
    }
    if(isInBounds(x-1,y)){
        if(b[x-1][y]>b[x][y]+1 || b[x-1][y]==-1){
            a.x = x-1;
            a.y = y;
            q.push(a);
        }
    }
    if(isInBounds(x,y-1)){
        if(b[x][y-1]>b[x][y]+1 || b[x][y-1]==-1){
            a.x = x;
            a.y = y-1;
            q.push(a);
        }
    }
}

int main()
{
    ifstream fin("muzeu.in");
    ofstream fout("muzeu.out");
    fin>>n;
    char a;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fin>>a;
            if(a=='#'){
                b[i][j]=-2;
            }else if(a=='P'){
                b[i][j]=-1;
                nod x;
                x.x=i;
                x.y=j;
                x.d=0;
                q.push(x);
            }else{
                b[i][j]=-1;
            }

        }
    }

    while(q.size()>0){
        nod x = q.front();
        q.pop();
        if(b[x.x][x.y]>=x.d || b[x.x][x.y]==-1)
            bfs(x.x, x.y, x.d);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            fout<<b[i][j]<<" ";
        }
        fout<<endl;
    }

    return 0;
}
