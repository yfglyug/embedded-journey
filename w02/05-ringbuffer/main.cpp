#include "ringbuffer.h"

int main(){
    int a[4];
    RingBuffer buf(4);
    cout<<"构造后 size() == "<<buf.size()<<endl;

    cout<<"空队列 pop → 返回  "<<buf.pop(a[1])<<"  size() 仍为  "<<buf.size()<<endl;

    cout<<"push 1,2,3,4 → push 5 → 依次 pop 得"<<endl;
    buf.push(1);
    buf.push(2);
    buf.push(3);
    buf.push(4);
    buf.push(5);
    for(int i=0;i<4;i++){
        buf.pop(a[i]);
        cout<<a[i]<<"  ";
    }
    cout<<endl;

    RingBuffer buf2(4);
    cout<<"push 1,2 → pop 得 ";
    buf2.push(1);
    buf2.push(2);
    buf2.pop(a[0]);
    cout<<a[0];
    buf2.push(3);
    buf2.push(4);
    buf2.push(5);
    cout<<endl<<"push 3,4,5 → 依次 pop 得 ";
    for(int i=0;i<4;i++){
        buf2.pop(a[i]);
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    RingBuffer b(4);
    b.push(1); b.push(2); b.push(3); b.push(4); b.push(5);   // 满，覆盖掉 1

    cout << "6) b[0]=" << b[0] << " b[1]=" << b[1]
        << " b[2]=" << b[2] << " b[3]=" << b[3]
        << "   （期望 2 3 4 5）" << endl;

    b[0] = 99;
    int v = 0;
    b.pop(v);
    cout << "   改 b[0]=99 后 pop → " << v << "   （期望 99，说明写进去的是真数据）" << endl;

    RingBuffer s(4);
    cout << "5) size：空=" << s.size();
    s.push(1); s.push(2);
    cout << " 半满=" << s.size();
    s.push(3); s.push(4);
    cout << " 满=" << s.size();
    s.push(5);
    cout << " 覆盖后=" << s.size() << "   （期望 0 2 4 4）" << endl;

}