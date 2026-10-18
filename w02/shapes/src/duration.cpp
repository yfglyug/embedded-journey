#include "duration.h"

Duration::Duration(int ms):ms(ms){}      // ← 单参构造，先别加 explicit

bool Duration::operator<(const Duration& d){
        return ms<d.ms;
}

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
    

