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
    RingBuffer(const RingBuffer &a);
    RingBuffer(RingBuffer&& other)noexcept;
    ~RingBuffer();
    RingBuffer& operator=(const RingBuffer &a);
    RingBuffer& operator=(RingBuffer&& other) noexcept;
    void push(int v);
    bool pop(int& out);
    int size()const;
    int& operator[](int i);
    const int& operator[](int i)const; 
};



