#pragma once

#include <iostream>
using namespace std;

class Vec2 {
public:
    Vec2(double x = 0, double y = 0);   // ← 这个单参构造，是后面能编过的关键

    friend ostream& operator<<(ostream& os, const Vec2& v);
    friend Vec2 operator+(const Vec2& a, const Vec2& b);     // 非成员
    friend Vec2 operator*(const Vec2& v, double k);          // 非成员：向量 × 数
    friend Vec2 operator*(double k, const Vec2& v);          // 非成员：数 × 向量

private:
    double x, y;
};
