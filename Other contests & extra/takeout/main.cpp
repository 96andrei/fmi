#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    //ifstream fin("date.in");
    //ofstream fout("date.out");

    int n,k;
    vector<int> c;
    vector<int> b;
    b.push_back(0);
    c.push_back(0);

    cin>>n>>k;

    string str = "";
    stack<int> st;
    stack<int> pos;
    for(int i=1; i<=n; i++){
        char car;
        cin>>car;
        str+=car;
        pos.push(i);
        if(car == 'b'){
            c.push_back(c.back());
            b.push_back(b.back()+1);
        }
        else{
            c.push_back(c.back()+1);
            b.push_back(b.back());
        }

        if(str.length()>k){
            //vector<int>::iterator *bi;
            //vector<int>::iterator *ci;
            int a1 = c[str.length()] - c[str.length() - k -1];
            int a2 = b[str.length()] - b[str.length() - k -1];
            if(a1 == 1 && a2 == k){
                str.erase(str.end()-k-1, str.end());
                c.erase(c.end()-k-1, c.end());
                b.erase(b.end()-k-1, b.end());
                for(int j=1; j<=k+1; j++){
                    int x = pos.top();
                    st.push(x);
                    pos.pop();
                }
            }

            /*int b=0, c=0;
            string::iterator it;
            for(it = str.end()-1; it>=str.end()-k-1; it--){
                if(*it == 'b')
                    b++;
                else
                    c++;
            }
            if(c==1 && b==k){
                str.erase(str.end()-k-1, str.end());
                for(int j=1; j<=k+1; j++){
                    int x = pos.top();
                    st.push(x);
                    pos.pop();
                }
            }*/
        }

    }

    while(st.size()>0){
        int nr = k+1;
        while(nr){
            nr--;
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }
    return 0;
}
