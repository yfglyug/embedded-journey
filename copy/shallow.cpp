#include <iostream>>
#include <cstring>
using namespace std;

class MyString
{
private:
    char *data;
public:
    MyString(const char *s){
        data = new char[strlen(s)+1];
        strcpy(data,s);
        cout << "    构造     data=" << (void*)data << "  内容=" << data << endl;
    }
    MyString(const MyString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "    复制构造 data=" << (void*)data << "  内容=" << data << endl;
    }
    ~MyString(){
        cout << "    析构     data=" << (void*)data << endl;
        delete[] data;
    }
    void modify(int i,char c){
        data[i]=c;
    }
    void print(const char *tag){
        cout << "    " << tag << " = " << data << endl;
    }
    char* addr() { 
        return data; 
    }
};

int main(){
    cout << "--- 构造 a ---" << endl;
    MyString a("hello");
    cout << "--- 用 a 初始化 b（本类没写复制构造）---" << endl;
    MyString b=a;

    cout << "\na.data 地址 = " << (void*)a.addr() << endl;
    cout << "b.data 地址 = " << (void*)b.addr() << endl;

    cout << "\n--- 把 b 的第一个字符改成 H ---" << endl;
    b.modify(0, 'H');
    a.print("a");
    b.print("b");

    cout << "\n--- main 结束，开始析构 ---" << endl;
    return 0;
}