#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x,y;
            cin>>x>>y;
            if(x==1 || y==1)
                count++;
        }
    }
    cout<<count;
    return 0;
}
