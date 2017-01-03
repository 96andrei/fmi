#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <queue>

#define N 1001

using namespace std;

int graf[N][N];
int residual[N][N];
bool visited[N];
int n,m;

vector<int> path;
vector<int> usablePath;

int flowNode, sinkNode;


bool bfs(int parent[]){
     memset(visited, 0, sizeof(visited));
     parent[flowNode] = -1;
     queue<int> q;
     q.push(flowNode);
     visited[flowNode] = true;

     while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=1; i<=n; i++){
            if(visited[i]==false && residual[u][i] > 0){
                q.push(i);
                visited[i]=true;
                parent[i]=u;
            }
        }
     }

     return (visited[sinkNode]==true);
}

int main()
{
    ifstream fin("date.in");
    fin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y,z;
        fin>>x>>y>>z;
        graf[x][y]=z;
    }

    fin>>flowNode>>sinkNode;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            residual[i][j]=graf[i][j];
        }
    }

    int max_flow = 0;
    int parent[N];
    while(bfs(parent)){

        int path_flow = INT_MAX;
        int u,v;
        for(v=sinkNode; v!=flowNode; v=parent[v]){
            u = parent[v];
            path_flow = min(path_flow, residual[u][v]);
        }

        for(v=sinkNode; v!=flowNode; v=parent[v]){
            u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    cout<<max_flow;

    return 0;
}
