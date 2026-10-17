#include <iostream>
using namespace std;

class Duration {
private:
    int ms;                 // 内部统一存毫秒
public:
    Duration(int ms):ms(ms){}      // ← 单参构造，先别加 explicit
    bool operator<(const Duration& d){
        return ms<d.ms;
    }
    friend Duration operator+(const Duration& d1,const Duration& d2);
    friend Duration operator*(const Duration& d1,int d2);
    friend Duration operator*(int d2,const Duration& d1);
    friend ostream& operator<<(ostream& os,const Duration& o);

};

Duration operator+(const Duration& d1,const Duration& d2){
        return Duration(d1.ms+d2.ms);
}

Duration operator*(const Duration& d1,int d2){
        return Duration(d1.ms*d2);
}

Duration operator*(int d2,const Duration& d1){
        return Duration(d1.ms*d2);
}

ostream& operator<<(ostream& os,const Duration& o){
        os<<o.ms<<"ms";
        return os;
}
int main() {
    Duration a(1500);
    Duration b(2500);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a * 2 = " << a * 2 << endl;
    cout << "2 * a = " << 2 * a << endl;
    cout << "2 + a = " << 2 + a << endl;
    cout << "a < b ? " << (a < b) << endl;
    return 0;
}
