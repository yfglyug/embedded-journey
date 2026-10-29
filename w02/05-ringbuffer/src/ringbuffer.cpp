#include "ringbuffer.h"

RingBuffer::RingBuffer(int cap):cap_(cap)
{
    buff_=new int[cap_];
    head_=cap_-1;
    tail_=0;
    count_=0;
     cout<<"构造函数"<<endl;
}
RingBuffer::RingBuffer(const RingBuffer &a){
    cap_=a.cap_;
    head_=a.head_;
    tail_=a.tail_;
    count_=a.count_;
    buff_=new int[cap_];
    int pos = a.head_;
    for (int i = 0; i < count_; i++)
    {
        pos = (pos + 1) % cap_;
        buff_[pos] = a.buff_[pos];
    }
    cout<<"复制构造"<<endl;
}
RingBuffer::RingBuffer(RingBuffer&& other)noexcept:
    buff_(other.buff_)                      // ① 把指针偷过来
    , cap_(other.cap_)
    , head_(other.head_)
    , tail_(other.tail_)
    , count_(other.count_)
{
    other.buff_  = nullptr;                   // ② 把源对象置空
    other.cap_   = 0;
    other.head_  = 0;
    other.tail_  = 0;
    other.count_ = 0;
}
RingBuffer::~RingBuffer()
{
    delete[] buff_;
    cout<<"析构函数"<<endl;
}
RingBuffer& RingBuffer::operator=(const RingBuffer &a){
    if(this== &a)return *this;
    delete[] buff_;
    cap_ = a.cap_;
    buff_ = new int[cap_];
    head_ = a.head_;
    tail_ = a.tail_;
    count_ = a.count_;
    int pos = a.head_;
    for (int i = 0; i < count_; i++)
    {
        pos = (pos + 1) % cap_;
        buff_[pos] = a.buff_[pos];
    }
    return *this;
}
RingBuffer& RingBuffer::operator=(RingBuffer&& other) noexcept {
    if (this == &other) return *this;         // ① 自移动保护

    delete[] buff_;                            // ② 先放掉自己原有的（跟拷贝赋值一样）

    buff_  = other.buff_;                      // ③ 偷
    cap_   = other.cap_;
    head_  = other.head_;
    tail_  = other.tail_;
    count_ = other.count_;

    other.buff_ = nullptr;                     // ④ 源对象松手
    other.cap_ = other.head_ = other.tail_ = other.count_ = 0;
    return *this;
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

