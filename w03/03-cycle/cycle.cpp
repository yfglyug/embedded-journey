#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Node {
public:
    std::string name_;
    std::shared_ptr<Node> next_;        // ← 两个方向都用 shared_ptr
    std::weak_ptr<Node>   prev_;       // ← 反向改弱引用

    Node(const std::string& n) : name_(n) {
        std::cout << "构造 " << name_ << "\n";
    }
    ~Node() {
        std::cout << "析构 " << name_ << "\n";
    }

    
};

int main() {
    {
        auto a = std::make_shared<Node>("A");
        auto b = std::make_shared<Node>("B");
        a->next_ = b;              // 强引用：A 拥有 B
        b->prev_ = a;              // 弱引用：B 只是"知道"A 在哪

        // a->next_ = b;
        // b->next_ = a;                    // ← 环在这里形成

        std::cout << "a 的计数=" << a.use_count() << "\n";
        std::cout << "b 的计数=" << b.use_count() << "\n";

        std::weak_ptr<Node> w = a;
if (w.expired()) {  /* 对象已经没了 */ }

if (auto s = w.lock()) {        // 提升成 shared_ptr（成功则计数临时 +1）
    std::cout << s->name_ << "\n";
}                                // s 出作用域，计数 -1

    }
    std::cout << "--- 离开作用域了 ---\n";
    return 0;
}
