#include "device.h"

int main() {
    std::unique_ptr<Device> a(new Device("a1"));

    takeRef(a);
    
    auto p2 = std::make_unique<Device>("lidar2");
    p2->run();

    std::cout << "--- 开始 ---\n";
    work();
    std::cout << "--- 结束 ---\n";
    return 0;
}
