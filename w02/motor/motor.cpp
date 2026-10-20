#include <iostream>

class Motor {
private:
    int pwm_;
protected:
    int voltage_;
public:
    Motor() : pwm_(0), voltage_(12) {
        std::cout << "[Motor 构造]\n";
    }
    void setPwm(int p) { pwm_ = p; }
    int  getPwm() const { return pwm_; }
    void run() const { std::cout << "run: pwm=" << pwm_ << "\n"; }
};

class StepperMotor : public Motor {
private:
    int stepsPerRev_;
public:
    StepperMotor(int spr) : stepsPerRev_(spr) {
        std::cout << "[StepperMotor 构造]\n";
    }
    void report() const {
        std::cout << "spr=" << stepsPerRev_
                  << ", pwm=" << getPwm()      // 基类 private → 只能走 public 接口
                  << ", volt=" << voltage_     // 基类 protected → 直接能用
                  << "\n";
    }
};

int main() {
    StepperMotor m(200);
    m.setPwm(60);        // 继承来的成员，对象直接调
    m.run();
    m.report();

    // 下面三行故意留着，逐个取消注释试
    // m.pwm_ = 1;          // 实验 1
    // m.voltage_ = 1;      // 实验 2
    // 实验 3：在 StepperMotor::report() 里加一行  pwm_ = 1;

    return 0;
}
