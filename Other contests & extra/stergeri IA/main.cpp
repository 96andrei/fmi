#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

struct xy{
    int x,y;
};

int main()
{
    int n,m,k;
    stack<xy> st;
    ifstream fin("stergeri.in");
    ofstream fout("stergeri.out");

    fin>>n>>m>>k;
    for(int i=0; i<m; i++){
        xy a;
        fin>>a.x>>a.y;
        st.push(a);
    }

    while(st.size()>0){
        xy a = st.top();
        if(k>=a.x)
            k+=a.y-a.x+1;
        st.pop();
    }

    fout<<k;

    return 0;
}
