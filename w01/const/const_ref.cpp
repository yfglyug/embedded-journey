#include <iostream>
using namespace std;

class Score {
public:
    Score(int s = 0) : score(s) { cout << "    构造 score=" << score << endl; }
    Score(const Score& o) : score(o.score) { cout << "    <<复制构造>>" << endl; }
    int value() const { return score; }
private:
    int score;
};

void byConstRef(const Score& x) { cout << "    byConstRef  收到 " << x.value() << endl; }
void byValue   (Score x)        { cout << "    byValue     收到 " << x.value() << endl; }
void byRef     (Score& x)       { cout << "    byRef       收到 " << x.value() << endl; }

int main() {
    Score a(7);
    const Score b(9);

    cout << "--- 传普通对象 a ---" << endl;
    byConstRef(a);          // 不复制
    byRef(a);               // 不复制
    byValue(a);             // 复制一份

    cout << "--- 传 const 对象 b ---" << endl;
    byConstRef(b);          // ✅ 能接，不复制
    byValue(b);             // ✅ 也能接（但复制一份）
    // byRef(b);            // ❌ binding reference of type 'Score&' to 'const Score' discards qualifiers

    cout << "--- 传临时对象 ---" << endl;
    byConstRef(Score(42));  // ✅ 能接临时对象，不复制
    // byRef(Score(42));    // ❌ cannot bind non-const lvalue reference to an rvalue
    return 0;
}
