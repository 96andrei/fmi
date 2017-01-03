#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <set>
using namespace std;

vector<char> sigma;
int q0;
vector<int> f;
vector<int> fFinal;
vector<int> q;
map<pair<int,char>, vector<int> > delta;
map<pair<int,char>, vector<int> > deltaFinal;

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

void dfs(int currentState, set<int> &closure){
    closure.insert(currentState);

    //verific daca exista lambda-tranzitie din starea curenta
    if(delta.find(make_pair(currentState, 'L')) == delta.end())
       return;

    //lista de stari in care se poate trece prin lambda
    vector<int> nextStates = delta[make_pair(currentState, 'L')];

    //dfs pe lambda-tranzitii
    for(int i=0; i<nextStates.size(); i++){
        dfs(nextStates[i], closure);
    }
}

set<int> Make_Closure(int state){
    set<int> closure;

    dfs(state, closure);

    return closure;
}

set<int> Make_Closure(set<int> states){
    set<int> closure;

    for(set<int>::iterator it = states.begin(); it != states.end(); it++){
        dfs(*it, closure);
    }

    return closure;
}

/*set<int> Make_Closure(vector<int> states){
    set<int> closure;

    for(vector<int>::iterator it = states.begin(); it != states.end(); it++){
        dfs(*it, closure);
    }

    return closure;
}*/

set<int> Make_Delta(set<int> states, char c){
    set<int> newDelta;

    //parcurge stari
    for(set<int>::iterator it = states.begin(); it != states.end(); it++){
        //verifica daca exista tranzitie cu litera curenta
        if(delta.find(make_pair(*it, c)) != delta.end()){
            //vectorul cu starile in care se ajunge
            vector<int> results = delta[make_pair(*it, c)];
            //adauga noile stari
            for(int i=0; i<results.size(); i++){
                newDelta.insert(results[i]);
            }
        }
    }

    return newDelta;
}

vector<int> SetToVector(set<int> mySet){
    vector<int> myVector;

    for(set<int>::iterator it = mySet.begin(); it!=mySet.end(); it++)
        myVector.push_back(*it);
    return myVector;
}

void LNFAtoNFAdelta(){
    //parcurge stari
    for(int i=0; i<q.size(); i++){
        int state = q[i];

        //inchiderea elementului curent
        set<int> closure = Make_Closure(state);
        for(int j=0; j<sigma.size(); j++){
            char character = sigma[j];
            //tranzitiile inchiderii
            set<int> deltaClosure = Make_Delta(closure, character);
            //inchiderea noilor tranzitii
            set<int> closureDelta = Make_Closure(deltaClosure);
            deltaFinal[make_pair(state, character)] = SetToVector(closureDelta);
        }
    }
}

void LNFAtoNFAfinalStates(){
    for(int i=0; i<f.size(); i++)
        fFinal.push_back(f[i]);

    set<int> q0Closure = Make_Closure(q0);
    for(set<int>::iterator it= q0Closure.begin(); it!=q0Closure.end(); it++){
        int state = *it;
        bool done = false;
        for(int i=0;i <f.size(); i++){
            if(f[i]==state){
                fFinal.push_back(q0);
                done = true;
                break;
            }
        }
        if(done)
            break;
    }
}

int main(){
    readAutomata();

    LNFAtoNFAdelta();

    LNFAtoNFAfinalStates();

    cout<<"Tranzitii\n";
    for(int i=0; i<q.size(); i++){
        int state = q[i];

        //inchiderea elementului curent
        set<int> closure = Make_Closure(state);
        for(int j=0; j<sigma.size(); j++){
            char character = sigma[j];

            cout<<state<<" "<<character<<" ";
            vector<int> d = deltaFinal[make_pair(state, character)];
            for(int k=0; k<d.size(); k++)
                cout<<d[k]<<" ";
            cout<<"\n";
        }
    }
    cout<<"Stari Finale\n";
    for(int i=0; i<fFinal.size(); i++)
        cout<<fFinal[i]<<" ";

    return 0;
}
