#include "ringbuffer.h"

RingBuffer::RingBuffer(int cap):cap_(cap)
{
    buff_=new int[cap_];
    head_=cap_-1;
    tail_=0;
    count_=0;
     cout<<"构造函数"<<endl;
}
RingBuffer::~RingBuffer()
{
    delete[] buff_;
    cout<<"西沟函数"<<endl;
}
void RingBuffer::push(int v){
    buff_[tail_]=v;
    tail_=(tail_+1)%cap_;
    if (count_ == cap_) {              // 满了：覆盖掉最老的
        head_ = (head_ + 1) % cap_;    // 最老的位置跟着前进
    } else {
        ++count_;                      // 没满：个数加一
    }
}
bool RingBuffer::pop(int& out){
    if(count_==0){
        return false;
    }
    head_=(head_+1)%cap_;
    out=buff_[head_];
    count_--;
    return true;
}
int RingBuffer::size()const{
    return count_;
}
int& RingBuffer::operator[](int i){
    return buff_[(head_ + 1 + i) % cap_];
}
const int& RingBuffer::operator[](int i)const{
    return buff_[(head_ + 1 + i) % cap_];
}

