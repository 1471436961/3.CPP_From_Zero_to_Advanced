/*************************************************************************
	> File Name: 29.inc_operator.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 04 Jul 2025 03:18:23 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;

class A {
public:
    A(int x = 0) : x(x) {}
    A &operator++() {
        x += 1;
        return *this;
    } // 注意与后自增返回值的区别
    A operator++(int) {
        A ret(*this);
        x += 1;
        return ret;
    } // 占位参数int，只是用来区分前自增和后自增
    int x;
};

// A &operator++(A &a) {
//    a.x += 1;
//    return a; 
// }

ostream &operator<<(ostream &out, const A &a) {
    out << "class A : x = " << a.x;
    return out;
}

int main() {
    A a(3);
    cout << a << endl;
    cout << "++a : " << ++a << endl;
    cout << "a++ : " << a++ << endl;
    cout << "a : " << a << endl;
    return 0;
}
