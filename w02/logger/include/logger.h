#pragma once

class Logger {
private:
    int fd_;        // 底层句柄
protected:
    int level_;     // 日志级别
public:
    Logger();                              // fd_ = 1, level_ = 0
    void write(const char* msg) const;     // 打印 "[0] hi" 这种
    int  getFd() const;
};

class ConsoleLogger : public Logger { public: void test(); };
class FileLogger    : protected Logger { public: void test(); };
class RawLogger     : private Logger  { public: void test(); };

void use(Logger* p);
