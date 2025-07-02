/*************************************************************************
	> File Name: 5.param_constructor.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 02 Jul 2025 08:07:38 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    // 有了有参构造后原来隐式的默认构造会被删除，需显式实现默认构造
    A() : A(100, 1000) {} // 委托构造，冒号后面叫做初始化列表
    A(int x, int y) {
        this->x = x, this->y = y; // this指针指向的是当前对象
    }
    void output() {
        cout << "(" << this->x << ", " << this->y << ")" << endl;
        return ;
    }

private:
    int x, y;
};

int main() {
    A a(10, 100), b(20, 23); // 有参构造即使用()通常也不会有歧义
    a.output();
    b.output();
    A c;
    c.output();
    return 0;
}
