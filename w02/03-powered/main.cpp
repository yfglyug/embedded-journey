#include "powered.h"

int main(){

    cout << "sizeof(Module) = " << sizeof(Module) << endl;
    Module m(12);
    m.setVolt(12);
    cout << m.Sensor::volt() << " " << m.Actuator::volt() << endl;   // 必须两个都是 12
}
