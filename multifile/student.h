#ifndef STUDENT_H     
#define STUDENT_H

#include <string>

class Student {
public:
    Student(std::string n);  
    void show() const;
private:
    std::string name;
};

#endif
