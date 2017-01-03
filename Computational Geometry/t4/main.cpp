#include <iostream>
#include <cmath>

#define PI 3.14159

using namespace std;

struct Vector2{
    float x,y;
    Vector2(float a, float b){
        x=a;
        y=b;
    }

    Vector2(){
    }

    float magnitude(){
        return sqrt(x * x + y * y);
    }
};

Vector2 getDirection(Vector2 p1, Vector2 p2){
    return Vector2(p2.x-p1.x, p2.y-p1.y);
}

float dot(Vector2 a, Vector2 b){
    return a.x*b.x+a.y*b.y;
}

float magnitude(Vector2 a){
    return sqrt(a.x * a.x + a.y * a.y);
}

float getCos(Vector2 a, Vector2 b){
    return dot(a,b) / (a.magnitude() * b.magnitude());
}

float equals(float x, float y){
    float m = x-y;
    if (abs(m) < 1e-5)
        return 0;

    return x-y;
}

int main()
{

    Vector2 a1,a2,a3,a4;

    cin>>a1.x>>a1.y>>a2.x>>a2.y>>a3.x>>a3.y>>a4.x>>a4.y;

    float mA2 = acos(getCos(getDirection(a2,a1), getDirection(a2,a3)));
    float mA4 = acos(getCos(getDirection(a4,a1), getDirection(a4,a3)));

    float sign = equals(mA2 + mA4, PI);
    if(sign == 0){
        cout<<"Pe disc";
    }else if(sign > 0){
        cout<<"In exterior";
    }else
        cout<<"In interior";

    cout<<"\n";

    Vector2 a1a2 = getDirection(a1,a2);
    Vector2 a3a4 = getDirection(a3,a4);
    Vector2 a1a4 = getDirection(a1,a4);
    Vector2 a2a4 = getDirection(a2,a3);

    if(equals(a1a2.magnitude() + a3a4.magnitude(), a1a4.magnitude() + a2a4.magnitude()) == 0)
       cout<<"Circumscriptibil";
    else
        cout<<"Nu este circumscriptibil";

    return 0;
}
