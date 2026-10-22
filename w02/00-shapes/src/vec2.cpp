#include "vec2.h"


Vec2::Vec2(double x , double y ) : x(x), y(y) { }

ostream& operator<<(ostream& os, const Vec2& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

Vec2 operator+(const Vec2& a, const Vec2& b) {
    return Vec2(a.x + b.x, a.y + b.y);
}

Vec2 operator*(const Vec2& v, double k) {
    return Vec2(v.x * k, v.y * k);
}

Vec2 operator*(double k, const Vec2& v) {
    return Vec2(v.x * k, v.y * k);       // 和上面数学上是一回事，但参数顺序不同
}