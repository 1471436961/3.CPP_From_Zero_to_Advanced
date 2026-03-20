/*************************************************************************
	> File Name: 34.rvo.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 04 Jul 2025 06:57:17 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << this << " : default constructor" << endl;
    }
    A(const A &a) {
        cout << this << " : copy constructor" << endl;
    }
};

A f() {
    A temp;
    cout << "temp : " << &temp << endl;
    return temp;
}

int main() {
    // Ubuntu 22.04.05 LTS环境
    // 直接g++编译：一次默认构造
    // 使用-fno-elide-constructors参数关闭返回值优化：默认构造和拷贝构造各一次
    // -fno-elide-constructors -std=c++11 一次默认构造，两次拷贝构造
    A a = f();
    cout << "a : " << &a << endl;
    return 0;
}
