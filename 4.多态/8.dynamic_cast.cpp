/*************************************************************************
	> File Name: 8.dynamic_cast.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 06 Jul 2025 03:20:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {
public:
    B() : x(1000), y(999) {}
    void output() {
        cout << "x = " << x << ", y = " << y << endl;
        return ;
    }
    int x, y;
};

int main() {
    // A *p1 = new A();
    B *p1 = new B();
    Base *p2 = p1; // 子类指针到父类指针的隐式类型转换，无需static_cast
    B *p3 = dynamic_cast<B *>(p2); // static_cast不安全
    if (p3 == nullptr) {
        cout << "convert failed" << endl;
    } else {
        p3->output(); // 用static_cast则会访问到不属于A类的地址
    }
    return 0;
}
