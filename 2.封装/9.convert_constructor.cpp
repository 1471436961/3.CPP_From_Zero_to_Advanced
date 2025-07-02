/*************************************************************************
	> File Name: 9.convert_constructor.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 02 Jul 2025 10:34:43 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A(int z) : x(z), y(z) {
        cout << this << " : convert constructor" << endl;
    }
    void operator=(const A &a) {
        this->x = a.x;
        this->y = a.y;
        cout << this << " operator=" << endl;
        return ;
    }
    void output() {
        cout << "(" << x << ", " << y << ")" << endl;
        return ;
    }

private:
    int x, y;
};

int main() {
    A a(3), b{4}, c = 5; // 转换构造的三种调用方式
    a.output();
    b.output();
    c.output();
    a = 4; // 先以4为参数调用转换构造形成匿名对象，再将该对象赋值给a
    a.output();
    return 0;
}
