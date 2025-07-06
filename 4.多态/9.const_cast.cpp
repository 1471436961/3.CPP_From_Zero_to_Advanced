/*************************************************************************
	> File Name: 9.const_cast.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 06 Jul 2025 04:04:28 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() : x(11), y(22) {}
    void output() const {
        cout << "x = " << x << ", y = " << y << endl;
        return ;
    }
    int x, y;
};

void test1() {
    const int x = 123;
    const int *p1 = &x;
    int *p2 = const_cast<int *>(p1); // 去掉指针指向类型的const
    cout << *p1 << endl;
    *p2 = 456;
    cout << *p1 << endl;
    return ;
}

void test2() {
    const A a;
    A &a2 = const_cast<A &>(a); // 去掉对象的const，绑定到非const的引用上
    a.output(); // const类型的对象只能调用const类型的方法
    a2.x = 33;
    a.output();

    const A *p1 = &a;
    A *p2 = const_cast<A *>(p1); // 去掉指针指向类型的const
    p1->output();
    p2->x = 44;
    p1->output();
    return ;
}

int main() {
    test1();
    test2();
    return 0;
}
