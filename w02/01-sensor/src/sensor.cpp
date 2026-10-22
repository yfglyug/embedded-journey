#include "sensor.h"
#include <iostream>
using namespace std;

Calib::Calib(){
    cout<<"Calib  构造"<<endl;
}
Calib::~Calib(){
    cout<<"Calib  析构"<<endl;
}


Sensor::Sensor(int id ):id_(id){
    cout<<"构造sensor"<<endl;
}
Sensor::~Sensor(){
    cout<<"析构sensor"<<endl;
}
void Sensor::setRaw(int r){
    raw_=r;
}
int  Sensor::getRaw() const{
    return raw_;
}
int  Sensor::getId() const{
    return id_;
}

TempSensor::TempSensor(int id, double scale):Sensor(id),scale_(scale),cal_(){
    cout<<"析构TempSensor"<<endl;
}
TempSensor::~TempSensor(){
    cout<<"析构TempSensor"<<endl;
}
double TempSensor::celsius() const{
    return raw_ * scale_;
}    // 返回 raw_ * scale_
void   TempSensor::dump() const{
    cout<<"id="<<getId()<<"  raw="<<raw_<<"  celsius="<<celsius()<<endl;
}        // 打印 id / raw / celsius


