#include <iostream>
#include <string>

using namespace std;

char list[3];

bool isInList(char c){
    bool result = false;
    if(list[0]==c)
        result = true;
    if(list[1]==c)
        result = true;
    return result;
}

int main()
{
    string str[100];
    int nrMax = 0, n;
    char letters[27] ="abcdefghijklmnopqrstuvwxyz";


    cin>>n;
    for(int i=0; i<n; i++){
        cin>>str[i];
    }

    for(int i=0; i<26; i++){
        list[0]=letters[i];
        for(int j=i+1; j<26; j++){
            list[1]=letters[j];
            int nrTemp = 0;
            for(int k=0; k<n; k++){
                string s = str[k];
                bool sem = true;
                for(int x=0; x<s.length(); x++){
                    if(!isInList(s[x])){
                        sem=false;
                        break;
                    }
                }
                if(sem){
                    nrTemp+=s.length();
                }
            }
            if(nrTemp > nrMax)
                nrMax = nrTemp;
        }
    }


    cout<<nrMax;

    return 0;
}
