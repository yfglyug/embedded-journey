#include <iostream>
using namespace std;

class A {
public:
    A()        { cout << "普通构造" << endl; }
    A(A o)     { cout << "复制构造" << endl; }    // ← 参数是"值"，不是引用
};

int main() {
    A a;
    A b = a;
    return 0;
}
