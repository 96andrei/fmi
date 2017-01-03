#include <fstream>
#include <stack>

using namespace std;

int main()
{
    ifstream fin("secv6.in");
    ofstream fout("secv6.out");
    stack<int> st;
    int n;
    int x[8192];
    fin>>n;
    int count = 0;
    int m = (n<8192) ? n : 8192;
    for(int i=0; i<m; i++){
        fin>>x[i];
    }
    for(int i=0; i<n; i++){
        int a = i + (x[i/8192]^x[i%8192]);
        bool wasEqual = false;
        while(st.size()>0 && a>=st.top()){
            if(a>st.top())
                count++;
            if(a==st.top())
                wasEqual = true;
            st.pop();
        }
        if(wasEqual || (st.size()>0 && !wasEqual))
            count++;
        st.push(a);
    }
    fout<<count;
    return 0;
}
