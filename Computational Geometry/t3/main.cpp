#include <iostream>
#include <cmath>

using namespace std;

struct Vector2f{
    float x,y;
};


float sqrDistance(Vector2f p1, Vector2f p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}


float sqrDistance(Vector2f p){
    Vector2f zero;
    zero.x = -1e5;
    zero.y = -1e5;
    return sqrDistance(p, zero);
}

struct Dreapta{

    float a;
    float b;
    float c;

    Vector2f p1,p2;

    Dreapta(Vector2f p1, Vector2f p2){
            //x(y1-y2) + y(x2-x1) + (x1y2 - x2y1) = 0

            if(sqrDistance(p1) < sqrDistance(p2)){
                this->p1 = p1;
                this->p2 = p2;
            }else{
                this->p1 = p2;
                this->p2 = p1;
            }
            a = p1.y - p2.y;
            b = p2.x - p1.x;
            c = p1.x * p2.y - p2.x * p1.y;
            //cout<<a<<" "<<b<<" "<<c<<"\n";
        }
};

float getDelta(Dreapta d1, Dreapta d2){
    float delta =  d1.a * d2.b - d1.b * d2.a;
    //cout<<delta<<"\n";
    return delta;
}

Vector2f getSinglePoint(Dreapta d1, Dreapta d2){
    float delta = getDelta(d1,d2);
    //cout<<delta<<"\n";

    float x = ((-d1.c * d2.b) - (d1.b * -d2.c)) / delta;
    float y = ((d1.a * -d2.c) - (-d1.c * d2.a)) / delta;

    Vector2f result;
    result.x = x;
    result.y = y;

    return result;
}

bool isInSegment(Vector2f p, Vector2f a1, Vector2f a2){
    bool onX = p.x >= a1.x && p.x <= a2.x || p.x >= a2.x && p.x <= a1.x;
    bool onY = p.y >= a1.y && p.y <= a2.y || p.y >= a2.y && p.y <= a1.y;
    return onX && onY;
    //return (p.x >= a1.x && p.x <= a2.x && p.y >= a1.y && p.y <= a2.y) || (p.x >= a2.x && p.x <= a1.x && p.y >= a2.y && p.y <= a1.y);
}

bool equals(float x, float y){
    return (fabs(x - y) < 1e-5);
}

bool proportional(Dreapta d1, Dreapta d2){
    return equals(d1.a * d2.b, d1.b * d2.a) && equals(d1.b * d2.c, d1.c * d2.b) && equals(d1.a * d2.c, d1.c * d2.a);
}

Vector2f getClosest(Vector2f p1, Vector2f p2){
    if(sqrDistance(p1) < sqrDistance(p2))
        return p1;
    return p2;
}

int main()
{
    Vector2f a1,a2,a3,a4;

    cin>>a1.x>>a1.y>>a2.x>>a2.y>>a3.x>>a3.y>>a4.x>>a4.y;

    Dreapta a1a2(a1,a2);
    Dreapta a3a4(a3,a4);

    if(getDelta(a1a2, a3a4) != 0){
        Vector2f p = getSinglePoint(a1a2, a3a4);
        //cout<<p.x<<" "<<p.y;
        if(isInSegment(p, a1, a2) && isInSegment(p,a3,a4))
            cout<<"Intersectie in "<<p.x<<" "<<p.y<<", delta != 0";
        else
            cout<<"Nu are solutie, delta != 0, dar punctul nu apartine ambelor segmente";
        return 0;
    }

    if(proportional(a1a2, a3a4)){
        if(sqrDistance(a1a2.p1) >= sqrDistance(a3a4.p1) && sqrDistance(a3a4.p2) >= sqrDistance(a1a2.p1)){


            Vector2f p1 = a1a2.p1;
            Vector2f p2 = getClosest(a1a2.p2, a3a4.p2);

            if(p1.x == p2.x && p1.y == p2.y){
                cout<<"Intersectie in "<<p1.x<<" "<<p1.y<<", delta = 0";
            }else{
                cout<<"Segmentul dintre ["<<p1.x<<","<<p1.y<<"] si ["<<p2.x<<","<<p2.y<<"]";
            }
            return 0;
        }else if(sqrDistance(a1a2.p1) <= sqrDistance(a3a4.p1) && sqrDistance(a1a2.p2) >= sqrDistance(a3a4.p1)){
            Vector2f p1 = a3a4.p1;
            Vector2f p2 = getClosest(a1a2.p2, a3a4.p2);

            if(p1.x == p2.x && p1.y == p2.y){
                cout<<"Intersectie in "<<p1.x<<" "<<p1.y<<", delta = 0";
            }else{
                cout<<"Segmentul dintre ["<<p1.x<<","<<p1.y<<"] si ["<<p2.x<<","<<p2.y<<"]";
            }
            return 0;

            return 0;
        }
    }

    cout<<"Nu avem solutie, delta = 0 si rang != 1";

    return 0;
}
