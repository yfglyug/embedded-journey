#include <iostream>
using namespace std;

class Vec2 {
public:
    Vec2(double x = 0, double y = 0) : x(x), y(y) { }   // ← 这个单参构造，是后面能编过的关键

    friend ostream& operator<<(ostream& os, const Vec2& v);
    friend Vec2 operator+(const Vec2& a, const Vec2& b);     // 非成员
    friend Vec2 operator*(const Vec2& v, double k);          // 非成员：向量 × 数
    friend Vec2 operator*(double k, const Vec2& v);          // 非成员：数 × 向量

private:
    double x, y;
};

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

int main() {
    Vec2 a(1, 2), b(3, 4);

    cout << "a = " << a << "   b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a * 2 = " << a * 2 << endl;
    cout << "2 * a = " << 2 * a << endl;
    cout << "2 + a = " << 2 + a << endl;      // ← 这一行是重点
    return 0;
}
