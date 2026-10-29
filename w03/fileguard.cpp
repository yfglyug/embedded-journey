#include <cstdio>
#include <iostream>
using namespace std;

class FileGuard {
private:
    FILE* fp_;
public:
    explicit FileGuard(const char* path) : fp_(fopen(path, "r")) {
        std::cout << "打开 " << path << "\n";
    }
    ~FileGuard() {
        if (fp_) {
            fclose(fp_);
            std::cout << "已关闭\n";
        }
    }
    FILE* get() const { return fp_; }
    bool  ok()  const { return fp_ != NULL; }
};

void readIt(bool failEarly) {
    FileGuard g("test.txt");
    if (!g.ok()) { std::cout << "打不开\n"; return; }

    if (failEarly) {
        std::cout << "中途 return\n";
        return;                    // ← 注意这里，没有 fclose
    }
    std::cout << "读完\n";
}                              // ← 不管从哪条路出去，析构都会执行

// 反例：手动管理，忘了关
void leakFd() {
    for (int i = 0; i < 2000; ++i) {
        FILE* fp = fopen("test.txt", "r");
        if (fp == NULL) {
            cout << "第 " << i << " 次打不开了 —— 句柄用完了" << endl;
            return;
        }
        // 故意不写 fclose
    }
    cout << "2000 次都成功了" << endl;
}

// 对照：用 RAII
void okFd() {
    for (int i = 0; i < 2000; ++i) {
        FileGuard g("test.txt");
    }
    cout << "RAII 版 2000 次都正常" << endl;
}

int main() {
    leakFd();
    okFd();
    std::cout << "--- 正常 ---\n";  readIt(false);
    std::cout << "--- 提前返回 ---\n"; readIt(true);
    return 0;
}
