#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    vector<char> st;
    ifstream fin("trompeta.in");
    ofstream fout("trompeta.out");
    fin>>n>>m;
    for(int i=1; i<=n; i++){
        char x;
        fin>>x;
        if(st.empty()){
            st.push_back(x);
            continue;
        }

        while(st.back() < x && st.size() + n-i > m-1){
            st.pop_back();
            if(st.empty())
                break;
        }
        if(st.size() < m)
            st.push_back(x);
    }
    string sts(st.begin(), st.end());
    fout<<sts;
    return 0;
}
