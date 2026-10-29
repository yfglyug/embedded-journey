#include "device.h"

Device::Device(const char* n) : name_(n) { std::cout << "构造 " << name_ << "\n"; }
Device::~Device() { std::cout << "析构 " << name_ << "\n"; }
void Device::run() const { std::cout << name_ << " 运行\n"; }

void takeRef(const std::unique_ptr<Device>& q) { q->run(); } 
void take(std::unique_ptr<Device> q) { q->run(); }  

void work() {
    std::unique_ptr<Device> p(new Device("lidar"));
    p->run();
}   // ← 这里没有 delete，但一定会释放
