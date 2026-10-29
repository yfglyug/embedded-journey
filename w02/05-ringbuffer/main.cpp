#include "ringbuffer.h"
void f(RingBuffer x){
    x.push(66);
    int xx;
    x.pop(xx);
}
int main(){
    RingBuffer a(4);
    a.push(1); a.push(2);
    RingBuffer c(2);
    c = std::move(a);

    cout << "c.size=" << c.size() << "  c[0]=" << c[0] << "  c[1]=" << c[1] << "\n";
    cout << "a.size=" << a.size() << "\n";        // ← 只查 size，不读数据

    c = std::move(c);                             // 自移动，不能崩
    cout << "自移动后 c.size=" << c.size() << "\n";
    return 0;
}

// int main(){
//     RingBuffer a(4);
//     a.push(1); a.push(2);
    
//     int v;
//     for(int i=0;i<2;i++){
//     v=a.operator[](i);
//     cout<<"a("<<i<<")= "<<v<<endl;
//     }
//     RingBuffer b = std::move(a);
//     for(int i=0;i<2;i++){
//     v=b.operator[](i);
//     cout<<"b("<<i<<")= "<<v<<endl;
//     }
//     std::cout << a.size()<<endl;     // 0 —— 别指望还是 2

//     RingBuffer a(4);
//     a.push(1);
//     a.push(2);


//     RingBuffer b = a;        // ← 拷贝构造（编译器默认给的那个）
//     b.push(3);
//     b.operator[](0)=5;
//     RingBuffer c(2);
//     c = a;                     // ← 拷贝赋值
//     a=a;
//     c=b=a;
//     cout << "a.size=" << a.size() << "  b.size=" << b.size() << endl;
//     cout << "a[0]=" << a[0] << "  b[0]=" << b[0] << endl;

//     a.push(4); a.push(5); a.push(6);
//     int v;
//     a.pop(v);  a.pop(v);  a.pop(v);

//     f(a);
//     a.pop(v);cout<<"传进去后改 x，外面不受影响"<<v<<endl;

//     // 验收 5：拷贝后绕圈，逐个 [] 读，两个对象必须完全一致
// RingBuffer p(4);
// for (int i = 1; i <= 6; ++i) p.push(i);      // 绕了一圈，剩 3,4,5,6
// RingBuffer q = p;
// for (int i = 0; i < q.size(); ++i) cout << q[i] << " ";   // 期望 3 4 5 6
// q.push(99);                                   // 改 q，p 不能动
// for (int i = 0; i < p.size(); ++i) cout << p[i] << " ";   // 期望还是 3 4 5 6


    // int a[4];
    // RingBuffer buf(4);
    // cout<<"构造后 size() == "<<buf.size()<<endl;

    // cout<<"空队列 pop → 返回  "<<buf.pop(a[1])<<"  size() 仍为  "<<buf.size()<<endl;

    // cout<<"push 1,2,3,4 → push 5 → 依次 pop 得"<<endl;
    // buf.push(1);
    // buf.push(2);
    // buf.push(3);
    // buf.push(4);
    // buf.push(5);
    // for(int i=0;i<4;i++){
    //     buf.pop(a[i]);
    //     cout<<a[i]<<"  ";
    // }
    // cout<<endl;

    // RingBuffer buf2(4);
    // cout<<"push 1,2 → pop 得 ";
    // buf2.push(1);
    // buf2.push(2);
    // buf2.pop(a[0]);
    // cout<<a[0];
    // buf2.push(3);
    // buf2.push(4);
    // buf2.push(5);
    // cout<<endl<<"push 3,4,5 → 依次 pop 得 ";
    // for(int i=0;i<4;i++){
    //     buf2.pop(a[i]);
    //     cout<<a[i]<<"  ";
    // }
    // cout<<endl;
    // RingBuffer b(4);
    // b.push(1); b.push(2); b.push(3); b.push(4); b.push(5);   // 满，覆盖掉 1

    // cout << "6) b[0]=" << b[0] << " b[1]=" << b[1]
    //     << " b[2]=" << b[2] << " b[3]=" << b[3]
    //     << "   （期望 2 3 4 5）" << endl;

    // b[0] = 99;
    // int v = 0;
    // b.pop(v);
    // cout << "   改 b[0]=99 后 pop → " << v << "   （期望 99，说明写进去的是真数据）" << endl;

    // RingBuffer s(4);
    // cout << "5) size：空=" << s.size();
    // s.push(1); s.push(2);
    // cout << " 半满=" << s.size();
    // s.push(3); s.push(4);
    // cout << " 满=" << s.size();
    // s.push(5);
    // cout << " 覆盖后=" << s.size() << "   （期望 0 2 4 4）" << endl;

// }