#include <iostream>
#include <queue>

using namespace std;

int a[501][501];
int h, w;
int r1,c1,r2,c2;
int count;

bool isInBounds(int x, int y){
    //return(x >= 1 && x<=w && x>=c1 && x<=c2 && y>=1 && y<=h && y>=r1 && y<=r2 && a[x][y]==0);
    return(x >= 1 && x<=h && y>=1 && y<=w && a[x][y]==0);
}

int d=1;

void dfs(int x, int y){
    a[x][y]=d;
    d++;
    if(isInBounds(x+1, y)){
        dfs(x+1,y);
        count++;
    }
    if(isInBounds(x, y+1)){
        dfs(x,y+1);
        count++;
    }
    if(isInBounds(x-1, y)){
        dfs(x-1,y);
        count++;
    }
    if(isInBounds(x, y-1)){
        dfs(x,y-1);
        count++;
    }
}

int main()
{
    int q;
    cin>>h>>w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            char c;
            cin>>c;
            if(c=='.')
                a[i][j]=0;
            else
                a[i][j]=-1;
        }
    }

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            d = 1;
            if(a[i][j]==0)
                dfs(i,j);
        }
    }

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}
