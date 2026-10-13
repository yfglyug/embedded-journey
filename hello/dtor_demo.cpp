#include <iostream>
using namespace std;

class Box {
public:
    Box()  { cout << "构造 Box" << endl; }
    ~Box() { cout << "析构 Box" << endl; }   
};
int main() {
    cout << "--- main 开始 ---" << endl;
    Box b;
    cout << "--- main 结束 ---" << endl;
    return 0;
}