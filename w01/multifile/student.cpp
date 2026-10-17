#include "student.h"
#include <iostream>

Student::Student(std::string n) : name(n) {
}

void Student::show() const {
    std::cout << "姓名：" << name << std::endl;
}