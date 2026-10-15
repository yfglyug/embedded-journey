#include <iostream>
#include <cstring>
using namespace std;

class Str {
private:
    char* data;
    int   len;
public:
    Str(const char* s = "") {
        len  = strlen(s);
        data = new char[len + 1];
        strcpy(data, s);
        cout << "    构造        len=" << len << "   data=" << (void*)data << endl;
    }

    Str(const Str& o) {                       // 复制构造函数（2.7 的深拷贝）
        len  = o.len;
        data = new char[len + 1];
        strcpy(data, o.data);
        cout << "    复制构造    len=" << len << "   data=" << (void*)data << endl;
    }

    ~Str() {
        cout << "    析构        data=" << (void*)data << endl;
        delete[] data;
    }

    // ⚠️ 第一步：这里**故意空着**，不写 operator=
    //    第二步：把下面这段前后的  /*  和  */  去掉
    
    Str& operator=(const Str& o) {
        if (this == &o) return *this;     // ① 自赋值：直接走人，别动自己
        delete[] data;                    // ② 先释放自己的旧内存
        len  = o.len;
        data = new char[len + 1];         // ③ 再开一块新的
        strcpy(data, o.data);             // ④ 再拷内容
        cout << "    赋值运算符  len=" << len << "   data=" << (void*)data << endl;
        return *this;                     // ⑤ 返回引用 → 支持 d = c = a
    }
    

    void print(const char* tag) const {
        cout << "    " << tag << " = \"" << data << "\"   data=" << (void*)data << endl;
    }
};

// ===== 第一步：只有两件套，看 c = a 会怎样 =====
void step1() {
    Str a("hello");
    Str c("x");
    cout << "--- c = a 之前 ---" << endl;
    a.print("a");
    c.print("c");
    cout << "--- 执行 c = a ---" << endl;
    c = a;
    cout << "--- c = a 之后 ---" << endl;
    a.print("a");
    c.print("c");
}

// ===== 第二步：把 operator= 加上之后 =====
void step2() {
    Str a("hello");
    Str c("x");
    c = a;
    a.print("a");
    c.print("c");

    cout << "--- 链式赋值：d = c = a ---" << endl;
    Str d("y");
    d = c = a;
    d.print("d");

    cout << "--- 自赋值：a = a ---" << endl;
    a = a;
    a.print("a");
}

int main() {
    step2();        // ← 跑完第一步，把这一行改成  step2();
    return 0;
}
