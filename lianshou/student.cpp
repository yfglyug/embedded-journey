#include <iostream>
using namespace std;

class Student
{
private:
    int id;
    double score;
public:
    Student(int i,double s):id(i),score(s){}
    bool operator==(const Student& o)const{
        return id==o.id && score==o.score;
    }
    bool operator!=(const Student& o)const{
      return !(*this == o);
    }
    bool operator<(const Student& o)const{
        return score<o.score;
    }
    friend ostream& operator<<(ostream& os,const Student& v);
};

ostream& operator<<(ostream& os,const Student& v){
    os<<"["<<v.id<<" "<<v.score<<"]";
    return os;
}

int main() {
    Student a(1001, 85.5);
    Student b(1001, 85.5);
    Student c(1002, 60.0);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "a == b ? " << (a == b) << endl;
    cout << "a == c ? " << (a == c) << endl;
    cout << "a != c ? " << (a != c) << endl;
    cout << "a <  c ? " << (a < c)  << endl;
    cout << "c <  a ? " << (c < a)  << endl;

    cout << "混排：a=" << a << "  c=" << c << endl;

    Student d(1001, 99.0);          // 学号相同，分数不同
    cout << "a == d ? " << (a == d) << endl;    // 应该是 0
    cout << "a != d ? " << (a != d) << endl;    // 应该是 1

    const Student x(1000, 90.0);
    cout << "x == a ? " << (x == a) << endl;    // 加了 const 才能编过
    
    return 0;
}

