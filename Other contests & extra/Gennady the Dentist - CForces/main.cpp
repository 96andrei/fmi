#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, d[4000], v[4000], p[4000], q[4000];
    int qpos = 0;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>v[i]>>d[i]>>p[i];
    }

    for(int i=0; i<n; i++){
        if(p[i] < 0)
            continue;
        int change = v[i];
        int ad = 0;
        q[qpos]=i+1;
        qpos++;
        for(int j=i+1; j<n; j++){
            if(p[j]<0)
                continue;
            p[j]-=ad+change;
            if(change > 0)
                change--;
            if(p[j]<0){
                if(ad+d[j]>1000000)
                    ad=1000001;
                else
                    ad+=d[j];
            }
        }
    }

    cout<<qpos<<endl;
    for(int i=0; i<qpos; i++)
        cout<<q[i]<<" ";

    return 0;
}
