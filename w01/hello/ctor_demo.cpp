#include <iostream>
using namespace std;
 class Point
 {
 private:
    int x,y;
 public:
 Point()
 {
    x=0;
    y=0;
    cout<<"默认构造被调用"<<endl;
 }
 
Point(int a,int b)
 {
    x=a;
    y=b;
    cout<<"带参构造被调用"<<endl;
 }
 void show(){
    cout<<"坐标：（"<<x<<","<<y<<"）"<<endl;
 }
 };
 class Circle
 {
 private:
    double radius,pi;
 public:
 Circle(double r) : radius(r) , pi(3.14169)
 {
    cout<<"用初始化列表构造"<<endl;
 }
 double area(){
    return pi*radius*radius;
 }
 };

 int main(){
    Point p1;
    Point p2(3,4);
    p1.show();
    p2.show();

    Circle c(2.0);
    cout<<"面积："<<c.area()<<endl;
    return 0;
 }