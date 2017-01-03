#include <fstream>

using namespace std;

ifstream fin("psychtraining.in");
ofstream fout("psychtraining.out");

void dei(int n, int pas){
    if(pas == 0)
        return;
    bool swap = false;
    for(int i=0; i<n; i++){
        if(i%pas == 0)
            swap =!swap;
        if(swap)
            fout<<'a';
        else
            fout<<'b';
    }
    fout<<"\n";

    dei(n, pas/2);
}

int main()
{


    int n;

    fin>>n;

    int count = 0;
    int pas = 1;
    while(pas<n){
        pas<<=1;
        count++;
    }
    fout<<count<<"\n";
    dei(n, pas/2);

    return 0;
}
