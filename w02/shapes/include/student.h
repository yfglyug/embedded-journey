#pragma once

#include <iostream>
using namespace std;

class Student
{
private:
    int id;
    double score;
public:
    Student(int i,double s);
    bool operator==(const Student& o)const;
    bool operator!=(const Student& o)const;
    bool operator<(const Student& o)const;
    friend ostream& operator<<(ostream& os,const Student& v);
};

