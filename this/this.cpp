#include <iostream>
using namespace std;

class Counter
{
private:
    int value;
public:
    Counter(int v=0):value(v){} 
    Counter(const Counter& c):value(c.value){
        cout << "    <<复制构造被调用>>" << endl;
    }
    void setValue(int value){
        this->value=value;
    }
    Counter& add(int n){
        value+=n;
        return *this;
    }
    Counter addCopy(int n){
        value+=n;
        return *this;
    }
    void print(const char* tag) {
        cout << "    " << tag << "  value=" << value << "  this=" << (void*)this << endl;
    }
};

int main() {
    Counter c1(10), c2(20);
    c1.print("c1");
    c2.print("c2");
    cout << "    两个 this 不一样 -> this 指向调用它的那个对象\n" << endl;

    cout << "setValue(99)：参数名和成员名一样，用 this 区分" << endl;
    c1.setValue(99);
    c1.print("c1");

    cout << "\nadd 返回引用 -> 不复制，链式调用同一个对象" << endl;
    c1.add(1).add(2).add(3);
    c1.print("c1");

    cout << "\naddCopy 返回值 -> 会复制一份（对照组）" << endl;
    c2.addCopy(5).print("临时副本");
    c2.print("c2");
    return 0;
}
