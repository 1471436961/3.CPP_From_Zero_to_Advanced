/*************************************************************************
	> File Name: 16.delete_default.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 07:09:50 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() = delete;
    A(const A &a) = default; // 浅拷贝 
    ~A() = default;
}; // 对象三个最基本的构造/析构函数，delete和default起到提醒的作用

int main() {
    A a, b(a);
    return 0;
}
