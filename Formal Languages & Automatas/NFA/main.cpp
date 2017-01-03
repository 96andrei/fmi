#include <iostream>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

vector<char> sigma;
int q0;
vector<int> f;
vector<int> q;
map<pair<int,char>, vector<int> > delta;
vector<string> input;


void readAutomata(){
    ifstream fin("date.in");
    //stari
    int n;
    fin>>n;
    for(int i=0; i<n; i++){
        int x;
        fin>>x;
        q.push_back(x);
    }

    //alfabet
    int m;
    fin>>m;
    for(int i=0; i<m; i++){
        char x;
        fin>>x;
        sigma.push_back(x);
    }
    //stare initiala
    fin>>q0;

    //stari finale
    int o;
    fin>>o;
    for(int i=0; i<o; i++){
        int x;
        fin>>x;
        f.push_back(x);
    }

    //tranzitii
    int t;
    fin>>t;
    for(int i=0; i<t; i++){
        int x, p;
        char a;
        fin>>x>>a>>p;
        delta[make_pair(x, a)].push_back(p);
    }
    fin.close();
}

void readInput(){
    int n;
    ifstream fin("cuv.in");
    fin>>n;
    for(int i=0; i<n; i++){
        string s;
        fin>>s;
        input.push_back(s);
    }
    fin.close();
}

bool nfa(int currentState, int sIndex, int iNumber){
    //verific daca am cuvantul vid si starea curenta/initiala este stare finala
    if(input[iNumber][sIndex]=='#'){
        for(int i=0; i<f.size(); i++)
            if(currentState == f[i])
                return true;
        return false;
    }

    //verific daca am folosit ultima litera si sunt in stare finala
    if(sIndex == input[iNumber].size()){
        for(int i=0; i<f.size(); i++){
            if(currentState == f[i])
                return true;
        }
        return false;
    }

    bool wasSuccesful = false;
    //lambda
    vector<int> nextStates = delta[make_pair(currentState, '.')];
    for(int i=0; i<nextStates.size(); i++){
        if(!wasSuccesful && nextStates[i] != currentState)
            wasSuccesful = nfa(nextStates[i], sIndex, iNumber);
    }
    if(wasSuccesful)
        return wasSuccesful;

    //verific daca functia de tranzitie este definita pentru starea si caracterul curente
    if(delta.find(make_pair(currentState, input[iNumber][sIndex])) == delta.end())
       return false;

    //lista de stari in care se poate trece prin caracterul curent
    nextStates = delta[make_pair(currentState, input[iNumber][sIndex])];

    //verific toate ramurile nfa-uli pana una din ele accepta cuvantul
    for(int i=0; i<nextStates.size(); i++){
        if(!wasSuccesful)
            wasSuccesful = nfa(nextStates[i], sIndex+1, iNumber);
    }



    return wasSuccesful;
}

int main(){
    readAutomata();
    readInput();
    for(int i=0; i<input.size(); i++){
        cout<<nfa(q0, 0, i)<<"\n";
    }
    return 0;
}
