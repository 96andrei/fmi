#include <fstream>
#include <queue>

using namespace std;

int a[1002][1002];

int n,m,h;

struct nod{
    int x;
    int y;
};

queue<nod> q;

int nr = 0;

nod makeNod(int x, int y){
    nod n;
    n.x = x;
    n.y = y;
    return n;
}

void fill(int x, int y){
    if(x>=1 && y>=1 && x<=n && y<=m){
        if(a[x][y] != 0)
            nr++;
        a[x][y] = -1;
        if(a[x+1][y] > 0 && a[x+1][y] < h)
            q.push(makeNod(x+1, y));
        if(a[x-1][y] > 0 && a[x-1][y] < h)
            q.push(makeNod(x-1, y));
        if(a[x][y+1] > 0 && a[x][y+1] < h)
            q.push(makeNod(x, y+1));
        if(a[x][y-1] > 0 && a[x][y-1] < h)
            q.push(makeNod(x, y-1));
    }
}



int main()
{
    ifstream fin("tsunami.in");
    ofstream fout("tsunami.out");

    fin>>n>>m>>h;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            fin>>a[i][j];
                if(a[i][j]==0){
                    nod x;
                    x.x = i;
                    x.y = j;
                    q.push(x);
                }
        }
    }

    while(q.size() > 0){
        nod x = q.front();
        if(a[x.x][x.y] >= 0){
            fill(x.x, x.y);
        }
        q.pop();
    }

    fout<<nr;

    return 0;
}
