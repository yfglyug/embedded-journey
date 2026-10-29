#pragma once
#include <iostream>
#include <memory>

class Device {
private:
    const char* name_;
public:
    Device(const char* n);
    ~Device();
    void run() const;
};
void takeRef(const std::unique_ptr<Device>& q);
void take(std::unique_ptr<Device> q);
void work();
