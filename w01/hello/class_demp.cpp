#include <iostream>
#include <string.h>
using namespace std;

class Student{
    public:
    void setName(string n){
        name=n;
    }
    void show(){
        cout<<"姓名："<<name<<endl;
    }
    private:
    string name;
};

int main(){
    Student s;
    s.setName("小明");
    s.show();
    
    return 0;
}
