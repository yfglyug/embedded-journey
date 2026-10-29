#include <iostream>
#include <memory>
#include "device.h" 
void report(std::shared_ptr<Device> q) {          // ← 按值传参：拷贝一次
    std::cout << "  report 里 count=" << q.use_count() << "\n";
}                                                  // 出函数，q 死，计数 -1

int main() {
    auto p = std::make_shared<Device>("lidar");
    std::cout << "count=" << p.use_count() << "\n";      // 1

    {
        auto q = p;
        std::cout << "内层 count=" << p.use_count() << "\n";   // 2
        report(q);                                              // 传进去是 3
        std::cout << "  report 回来后 count=" << p.use_count() << "\n";
    }

    std::cout << "外层 count=" << p.use_count() << "\n";   // 1
    std::cout << "sizeof(shared_ptr)=" << sizeof(p) << "\n";
    std::cout << "sizeof(unique_ptr)=" << sizeof(std::unique_ptr<Device>) << "\n";
    return 0;                                              // p 死 → 0 → 析构
}
