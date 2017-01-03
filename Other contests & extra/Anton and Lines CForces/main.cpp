#include <stdio.h>
#include <vector>
#include <limits>

using namespace std;

struct coef{
    int nr;
    long double y;
};

float eps = numeric_limits<float>::epsilon();

void qs(vector<coef> &lines,int left,int right)
{
    long double piv;
    piv=lines[left + (right-left)/2].y;
    int i,j;
    i=left;
    j=right;
    while(i <= j)
    {
        while(lines[i].y < piv)
            i++;
        while(lines[j].y > piv)
            j--;

        if(i <= j)
        {
            coef aux=lines[i];
            lines[i]=lines[j];
            lines[j]=aux;
            i++;
            j--;
        }
    }
    if(i < right)
        qs(lines, i, right);
    if(left < j)
        qs(lines, left, j);

}

int main()
{
    int n;
    int x1, x2;
    vector<coef> x1v, x2v;

    scanf("%d%d%d", &n,&x1,&x2);

    bool found = false;

    for(int i=0; i<n; i++){
        int k,b;
        long double y;
        scanf("%d%d", &k, &b);
        coef temp;
        temp.y = (x1+eps)*k + b;
        temp.nr = i;
        x1v.push_back(temp);
        temp.y = (x2-eps)*k + b;
        temp.nr = i;
        x2v.push_back(temp);
    }

    qs(x1v, 0, n-1);
    qs(x2v, 0, n-1);

    for(int i=0; i<n; i++){
        if(x1v[i].nr != x2v[i].nr){
            printf("Yes");
            return 0;
        }
    }

    printf("No");

    return 0;
}
