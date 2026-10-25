#pragma once
#include <iostream>
using namespace std;

class RingBuffer
{
private:
    int* buff_;
    int cap_,head_,tail_,count_;
public:
    RingBuffer(int cap);
    ~RingBuffer();
    void push(int v);
    bool pop(int& out);
    int size()const;
    int& operator[](int i);
    const int& operator[](int i)const; 
};



