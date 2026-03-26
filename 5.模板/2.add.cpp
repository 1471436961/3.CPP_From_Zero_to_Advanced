/*************************************************************************
	> File Name: 2.add.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 26 Mar 2026 11:40:47 AM CST
 ************************************************************************/

#include <iostream>
#include <sstream>
using namespace std;

#define P(func) { \
    cout << #func << " = " << func << endl; \
}

// 直接 decltype(a + b) 会报错，因为此时还没有 a,b 变量 -> 匿名变量
// 但 decltype(T() + U()) 若 T 或 U 没有默认构造同样会报错
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
} // 返回值后置

void is_type(int a) {
    cout << "a is int" << endl;
    return ;
}

void is_type(double a) {
    cout << "a is double" << endl;
    return ;
}

class A {
public: 
    A(int x) : x(x) {}
    int x;
};

class B {
public:
    B(double x = 0) : x(x) {}
    double x;
}; // 参数 x 有默认值，故 B 有默认构造

string operator+(const A &a, const B &b) {
    ostringstream ss;
    ss << a.x << ", " << b.x;
    return ss.str();
} // 利用运算符重载告知编译器 A + B 的返回值类型

int main() {
    // cout << add(3.4, 6) << endl;
    P(add<double>(3.4, 6));
    P(add(3.4, 6));
    P(add(6, 3.4));
    // decltype 关键字：当成括号类表达式的类型
    decltype(3.4 + 6) a;
    is_type(a);

    A a1(9);
    B a2(3.4);
    P(add(a1, a2));
    return 0;
}
