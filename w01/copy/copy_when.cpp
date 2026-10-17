#include <iostream>
using  namespace std;
 class Point
 {
 private:
    int x,y;
 public:
    Point(int a=0,int b=0):x(a),y(b){
        cout<<"普通构造("<<x<<","<<y<<")"<<endl;
    }
    Point(const Point &p):x(p.x),y(p.y){
        cout<<"复制构造("<<x<<","<<y<<")"<<endl;
    }
    ~Point(){
        cout<<"析构("<<x<<","<<y<<")"<<endl;
    }
 };

 void byValue(Point p) {
    cout << "    -> 已进入 byValue 内部" << endl;
}

Point makePoint() {
    Point tmp(3, 4);
    cout << "    -> makePoint 准备 return" << endl;
    return tmp;
}

int main(){
    cout << "[1] 用已有对象初始化新对象" << endl;
    Point p1(1,2);
    Point p2(p1);
    Point p3=p1;

    cout << "\n[2] 函数按值传参" << endl;
    byValue(p1);

    cout << "\n[3] 函数按值返回" << endl;
    Point p4 = makePoint();

    cout << "\n[4] main 结束，开始析构" << endl;
    return 0;


}
 

 