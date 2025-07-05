/*************************************************************************
	> File Name: 3.inherit_pointer.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 05 Jul 2025 11:21:43 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Base {
public:
    Base(int x, int y) : x(x), y(y) {}
    int x, y;
};

class A : public Base {
public:
    A(int x, int y, int z) : Base(x, y), z(z) {}
    int z;
};

void func1(Base *p) {
    cout << "Base : " << p->x << ", " << p->y << endl;
    return ;
} // 子类的地址可以隐式的转换为父类的地址

ostream &operator<<(ostream &out, const Base &obj) {
    out << "Base (" << obj.x << ", " << obj.y << ")";
    return out;
} // 所有可以用在父类上的方法，都可以用在子类上

int main() {
    A a(3, 4, 5);
    func1(&a);
    Base &b = a; // 子类的对象也可以绑定到父类的引用上
    b.x = 5;
    b.y = 6;
    func1(&a);
    cout << a << endl;
    return 0;
}
