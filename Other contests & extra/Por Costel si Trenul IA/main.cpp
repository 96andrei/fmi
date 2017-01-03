#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("trenul.in");
    ofstream fout("trenul.out");

    int n,m;
    fin>>n>>m;
    int f = 1, l = n;
    int x;
    for(int i=0; i<m; i++){
        fin>>x;
        if(x== 1){
            fout<<f<<endl;
            f++;
        }else if(x == 3){
            fout<<f<<" ";
            f++;
            fout<<f<<" ";
            f++;
            fout<<f<<endl;
            f++;
        }else{
            fout<<l<<" ";
            l--;
            fout<<l<<endl;
            l--;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
