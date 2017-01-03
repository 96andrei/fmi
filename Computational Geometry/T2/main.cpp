#include <iostream>
#include <cmath>

using namespace std;

struct Vector2f{
    float x,y;
};

int sign(float nr){
    if(nr < 0)
        return -1;
    if(nr > 0)
        return 1;
    return 0;
}

bool equals(float x, float y){
    if (fabs(x - y) < 1e-5)
        return true;
    return false;
}

int orient(Vector2f a, Vector2f b, Vector2f c){
    return sign((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}

float aria(Vector2f a, Vector2f b, Vector2f c){
    return abs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}

bool isInTriangle(Vector2f a, Vector2f b, Vector2f c, Vector2f p){
    float area = aria(a,b,c);

    return equals(area ,aria(a,b,p) + aria(b,c,p) + aria(a,c,p));
}

int main()
{
    Vector2f a1,a2,a3,a4;
    cin>>a1.x>>a1.y>>a2.x>>a2.y>>a3.x>>a3.y>>a4.x>>a4.y;

    int l1 = orient(a1,a2,a3);
    int l2 = orient(a2,a3,a4);
    int l3 = orient(a3,a4,a1);

    if(l1==l2 && l2==l3)
        cout<<"Convex\n";
    else
        cout<<"Nu e convex\n";

    Vector2f p;
    cin>>p.x>>p.y;

    if(isInTriangle(a1,a2,a3,p) || isInTriangle(a1,a3,a4,p))
        cout<<"In interior";
    else
        cout<<"In exterior";

    return 0;
}
