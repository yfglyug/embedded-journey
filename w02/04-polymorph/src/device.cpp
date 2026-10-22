#include "device.h"


Device::Device(int id):id_(id){ 
    name_=new char[16];
    cout<<"Device 申请 16B"<<endl;
}
Device::~Device(){
    delete []name_;
    cout<<"~Device 释放"<<endl;
}
void Device::start() const{
    cout<<"Device start id="<<id_<<endl;
}      // 打印 "Device start id=N"
int  Device::id()    const{
    return id_;
}

Lidar::Lidar(int id, int rpm):Device(id),rpm_(rpm){
    model_=new char[32];
    cout<<"Lidar 申请 32B"<<endl;
}
Lidar::~Lidar(){
    delete []model_;
    cout<<"~Lidar 释放"<<endl;
}
void Lidar::start() const{
    cout<<"Lidar start rpm="<<rpm_<<endl;
}       // 打印 "Lidar start rpm=N"


Motor::Motor(int id, int pwm):Device(id),pwm_(pwm){

}
void Motor::start() const{
    cout<<"Motor start pwm="<<pwm_<<endl;
}       // 打印 "Motor start pwm=N"

