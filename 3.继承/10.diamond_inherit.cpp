/*************************************************************************
	> File Name: 10.diamond_inherit.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 05 Jul 2025 04:55:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    int x;
};

class B : virtual public A {
public:
    void set_x(int x) {
        this->x = x;
        return ;
    }
}; // 虚继承，同属父类的字段会进行合并

class C : virtual public A {
public:
    int get_x() { return this->x; }
};

class D : public B, public C {};

int main() {
    D obj;
    obj.set_x(3);
    cout << obj.get_x() << endl;
    return 0;
}
