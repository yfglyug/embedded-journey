#include "logger.h"
#include <iostream>
using namespace std;
 Logger::Logger(){
    fd_=1;
    level_=0;
 }                            // fd_ = 1, level_ = 0
void Logger::write(const char* msg) const{
    cout<<"["<<level_<<"]"<<msg<<endl;
}   // 打印 "[0] hi" 这种
int  Logger::getFd() const{
    return fd_;
}

void ConsoleLogger::test(){

}
void FileLogger::test(){

}
void RawLogger::test(){
    
}

void use(Logger* p){
    (void)p;
}
