#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <set>

#define mapIt map<char, vector<string> >::iterator
#define setIt set<char>::iterator

using namespace std;

set<char> M[100][100];

vector<char> gram;
map<char, vector<string> > prod;

int main(){
    int x,p;
    ifstream fin("date.in");
    fin>>x>>p;
    for(int i=0; i<x; i++){
        char c;
        fin>>c;
        gram.push_back(c);
    }
    for(int i=0; i<p; i++){
        char c;
        string s;
        fin>>c>>s;
        prod[c].push_back(s);
    }
    string cuv;
    fin>>cuv;
    fin.close();
    int n = cuv.length();
    for(int i=0; i<n; i++){
        for(mapIt it = prod.begin(); it!=prod.end(); it++){
            vector<string> v = it->second;
            for(int z=0; z<v.size(); z++)
                if(v[z][0] == cuv[i])
                    M[1][i+1].insert(it->first);
        }
    }

    for(int i=2; i<=n; i++){
        for(int j=1; j<=n-i+1; j++){
            for(int k=1; k<=i-1; k++){
                set<char> s1 = M[k][j];
                set<char> s2 = M[i-k][j+k];
                for(setIt it1 = s1.begin(); it1!=s1.end(); it1++){
                    for(setIt it2= s2.begin(); it2!=s2.end(); it2++){
                        string s = "00";
                        s[0]=*it1;
                        s[1]=*it2;
                        for(mapIt it = prod.begin(); it!=prod.end(); it++){
                            vector<string> v = it->second;
                            for(int z=0; z<v.size(); z++){
                                if(v[z] == s){
                                    M[i][j].insert(it->first);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i+1; j++){
            int count=0;
            set<char> s1= M[i][j];
            if(s1.size() == 0){
                cout<<"0";
                count++;
            }
            for(setIt it = s1.begin(); it!=s1.end(); it++){
                cout<<*it;
                count++;
            }
            for(int i=0; i<5-count; i++)
                cout<<" ";
        }
        cout<<"\n";
    }

    set<char> s1= M[n][1];
    for(setIt it = s1.begin(); it!=s1.end(); it++){
        if(*it == 'S'){
            cout<<"Acceptat";
            return 0;
        }
    }
    cout<<"Nu e acceptat";
    return 0;
}
