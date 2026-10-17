#include <iostream>
using namespace std;

class vec2
{
private:
    double x,y;
public:
    vec2(double x=0,double y=0):x(x),y(y){}
    bool operator==(const vec2& o)const{
        return x==o.x && y==o.y;
    }
    friend ostream& operator<<(ostream& os,const vec2& v);
};

ostream& operator<<(ostream& os,const vec2& v){
    os<<"("<<v.x<<","<<v.y<<")";
    return os;
}

int main() {
    vec2 a(1, 2), b(1, 2), c(3, 4);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "a == b ? " << (a == b) << endl;
    cout << "a == c ? " << (a == c) << endl;

    cout << "链式：a=" << a << "   c=" << c << endl;
    return 0;
}


