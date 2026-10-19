#include "sensor.h"
#include <iostream>
using namespace std;

int main(){
    TempSensor t(7, 0.5);
    t.setRaw(100);
    t.dump();

    return 0;
}
