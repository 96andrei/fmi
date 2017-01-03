#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==1){
        cout<<-1;
        return 0;
    }

    int x[4], y[4];
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }
    int result = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(x[i]!=x[j] && y[i]!=y[j]){
                int width = (x[i]>x[j]) ? x[i]-x[j] : x[j]-x[i];
                int height = (y[i]>y[j]) ? y[i]-y[j] : y[j]-y[i];
                result = width * height;
            }

        }
    }
    cout<<result;

    return 0;
}
