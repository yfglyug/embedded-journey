#include <iostream>
using namespace std;
class A
{
private:
    int id;
public:
    A(int n):id(n){
        cout<<"构造A   "<<id<<endl;
    }
    ~A(){
        cout<<"析构A  "<<id<<endl;
    }
};

A g(0);

int main(){
    cout<<"--- main 开始 ---"<<endl;
    A a1(1);
    {
        A a2(2);
        cout<<"（在代码块内）"<<endl;
    }
    cout << "--- main 结束 ---" << endl;
    return 0;
}

