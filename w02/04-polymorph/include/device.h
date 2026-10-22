#include <iostream>
using namespace std;

class Device {
protected:
    int id_;
    char* name_;
public:
    Device(int id = 0);
    virtual ~Device();
    virtual void start() const;       // 打印 "Device start id=N"
    int  id()    const;
};

class Lidar : public Device {
private:
    int rpm_;
    char* model_;
public:
    Lidar(int id, int rpm);
    ~Lidar();
    void start() const;       // 打印 "Lidar start rpm=N"
};

class Motor : public Device {
private:
    int pwm_;
public:
    Motor(int id, int pwm);
    void start() const;       // 打印 "Motor start pwm=N"
};
