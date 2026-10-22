#include "powered.h"

Powered::Powered(int v):volt_(v) { std::cout << "Powered\n"; }
int Powered::volt() const{return volt_;}
void Powered::setVolt(int v){volt_=v;}



Sensor::Sensor(int v) : Powered(v) { std::cout << "Sensor\n"; }     // ← 这行会被忽略！



Actuator::Actuator(int v) : Powered(v) { std::cout << "Actuator\n"; } // ← 这行也会被忽略！



Module::Module(int v) : Powered(v), Sensor(v), Actuator(v) {        // ← 真正生效的是这一行
    std::cout << "Module\n";
}



