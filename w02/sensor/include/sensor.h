#pragma once

class Calib
{
public:
    Calib();
    ~Calib();
};



class Sensor {
private:
    int id_;
    
protected:
    int raw_;
public:
    Sensor(int id );
    ~Sensor();
    void setRaw(int r);
    int  getRaw() const;
    int  getId() const;
};

class TempSensor : public Sensor {
private:
    double scale_;
    Calib cal_;
public:
    TempSensor(int id, double scale);
    ~TempSensor();
    double celsius() const;     // 返回 raw_ * scale_
    void   dump() const;        // 打印 id / raw / celsius
};
