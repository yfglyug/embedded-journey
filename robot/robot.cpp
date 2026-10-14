#include <iostream>
using namespace std;

class Robot{
    private:
    const char* name;
    static int count;
    public:
    Robot(const char* n){
        name = n;
        count++;
        cout<<"    构造 "  << name << "，当前对象数 = " << count << endl;
    }
    ~Robot(){
        count--;
        cout << "    析构 " << name << "，当前对象数 = " << count << endl;
    }
    void show(){
        cout << "    我是 " << name << "，当前对象数 = " << count << endl;
    } 
    static int getCount(){
        return count;
    }
};

int Robot::count=0;

int main(){
    cout << "--- 不需要对象，就能问类的信息 ---" << endl;
    cout << "sizeof(Robot) = " << sizeof(Robot) << " 字节（静态成员不占对象空间）" << endl;
    cout << "Robot::getCount() = " << Robot::getCount() << endl;

    cout << "\n--- 造两个对象 ---" << endl;
    Robot r1("R2-D2");
    Robot r2("C-3po");

    cout << "\n--- 静态成员共享：换个对象看同一个数 ---" << endl;
    r1.show();
    r2.show();
    cout<< "r1.getCount() = " << r1.getCount() << " （通过对象也能调）" << endl;
    
    cout << "\n--- main 结束，开始析构 ---" << endl;
    return 0;
}