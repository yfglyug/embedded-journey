#include "vec2.h"
#include "student.h"
#include "duration.h"

int main() {
    {
    Vec2 a(1, 2), b(3, 4);

    cout << "a = " << a << "   b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a * 2 = " << a * 2 << endl;
    cout << "2 * a = " << 2 * a << endl;
    cout << "2 + a = " << 2 + a << endl;      // ← 这一行是重点
    }
    {
    Student a(1001, 85.5);
    Student b(1001, 85.5);
    Student c(1002, 60.0);
    Student d(1001, 99.0);
    const Student x(1000, 90.0);

    cout << "a = " << a << endl;
    cout << "a == b ? " << (a == b) << endl;
    cout << "a == c ? " << (a == c) << endl;
    cout << "a != c ? " << (a != c) << endl;
    cout << "a <  c ? " << (a < c)  << endl;
    cout << "a == d ? " << (a == d) << endl;
    cout << "a != d ? " << (a != d) << endl;
    cout << "x == a ? " << (x == a) << endl;
    }
    
    {
    Duration a(1500);
    Duration b(2500);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a * 2 = " << a * 2 << endl;
    cout << "2 * a = " << 2 * a << endl;
    cout << "2 + a = " << 2 + a << endl;
    cout << "a < b ? " << (a < b) << endl;
    }
    return 0;
}

