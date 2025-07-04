/*************************************************************************
	> File Name: 28.less_operator.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 04 Jul 2025 02:48:05 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;

class A {
public:
    A(int x = 0) : x(x) {}
    bool operator<(const A &a) const {
        return x < a.x;
    } // const类型的对象只能调用const类型的方法
    // stl中涉及到自定义比较时，只需要用户重载小于运算符，
    // 因为其他运算符都可以通过小于运算符实现
    bool operator>(const A &a) const {
        return a < *this;
    }
    bool operator==(const A &a) const {
        return !(*this < a) && !(a < *this);
    }
    bool operator!=(const A &a) const {
        return !(*this == a);
    }
    bool operator<=(const A &a) const {
        return (*this < a) || (*this == a);
    }
    bool operator>=(const A &a) const {
        return (a < *this) || (*this == a);
    }
    int x;
};

map<A, int> h;

#define P(stmt) {\
    cout << #stmt << " : " << (stmt) << endl; \
}

int main() {
    A a(3), b(4);
    h[a] = 123;
    cout << h[a] << endl;
    P(a < b);
    P(a > b);
    P(a == b);
    P(a != b);
    P(a <= b);
    P(a >= b);
    return 0;
}
