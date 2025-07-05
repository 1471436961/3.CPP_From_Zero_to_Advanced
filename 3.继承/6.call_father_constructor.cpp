/*************************************************************************
	> File Name: 6.call_father_constructor.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 05 Jul 2025 02:56:31 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Base {
public:
    Base() : x(3) {
        cout << "Base default constructor" << endl;
    }
    Base(int x) : x(x) {
        cout << "Base(int x) constructor" << endl;
    }
    Base(const Base &obj) {
        cout << "Base copy constructor" << endl;
        this->x = obj.x;
    }
    int x;
};

class A : public Base {
public:
    A() : y(4) {
        cout << "A default constructor" << endl;
    }
    A(const A &obj) : Base(obj) {
        cout << "A copy constructor" << endl;
        this->y = obj.y;
    } // 若不显式调用父类的拷贝构造，默认调用的是父类的默认构造
    A &operator=(const A &obj) {
        this->y = obj.y;
        this->Base::operator=(obj); 
        // 显式调用父类的赋值运算符(也是一种方法)，完成父类属性的更改
        return *this;
    }
    int y;
};

ostream &operator<<(ostream &out, const A &a) {
    out << "class A (" << a.x << ", " << a.y << ")";
    return out;
}

int main() {
    A a, c;
    cout << "a : " << a << endl;
    cout << "c : " << c << endl; 
    a.x = 1000, a.y = 999;
    c = a;
    cout << "after(c = a) c : " << c << endl;
    A b = a;
    cout << b << endl;
    return 0;
}
