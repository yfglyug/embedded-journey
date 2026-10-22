#include <iostream>
using namespace std;

class Powered {
public:
    int volt_;
    Powered(int v);
    int volt() const;
    void setVolt(int v);
};

class Sensor : virtual public Powered {
public:
    Sensor(int v);    // ← 这行会被忽略！
};

class Actuator : virtual public Powered {
public:
    Actuator(int v); // ← 这行也会被忽略！
};

class Module : public Sensor, public Actuator {
public:
    Module(int v);
};
