#include "student.h"

Student::Student(int i,double s):id(i),score(s){}
bool Student::operator==(const Student& o)const{
    return id==o.id && score==o.score;
}
bool Student::operator!=(const Student& o)const{
return !(*this == o);
}
bool Student::operator<(const Student& o)const{
    return score<o.score;
}

ostream& operator<<(ostream& os,const Student& v){
    os<<"["<<v.id<<" "<<v.score<<"]";
    return os;
}
