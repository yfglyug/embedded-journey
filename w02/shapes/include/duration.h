#include <iostream>
using namespace std;

class Duration {
private:
    int ms;                 // 内部统一存毫秒
public:
    Duration(int ms);     // ← 单参构造，先别加 explicit
    bool operator<(const Duration& d);
    friend Duration operator+(const Duration& d1,const Duration& d2);
    friend Duration operator*(const Duration& d1,int d2);
    friend Duration operator*(int d2,const Duration& d1);
    friend ostream& operator<<(ostream& os,const Duration& o);

};
