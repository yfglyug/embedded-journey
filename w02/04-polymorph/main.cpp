#include "device.h"

int main(){
    cout << "=== 虚析构实验开始 ===" << endl;
    {
        Device* p = new Lidar(3, 800);
        delete p;
    }
    cout << "=== 虚析构实验结束 ===" << endl;

    // ↓↓↓ 以下是你原来的验证，原样保留（当回归测试）↓↓↓
    Lidar l(1, 600); l.start();
    Motor m(2, 20);
    // Device d = l; d.start();        // ← 注释掉：裸指针 + 切片 = double free

    cout << sizeof(Device) << " " << sizeof(Lidar) << endl;

    Device* list[2] = {&l, &m};
    for (int i = 0; i < 2; ++i) list[i]->start();

    Device& r = l;
    r.start();
    return 0;
}

