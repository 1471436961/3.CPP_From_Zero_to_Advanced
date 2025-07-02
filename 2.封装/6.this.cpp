/*************************************************************************
	> File Name: 6.this.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 02 Jul 2025 08:33:01 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() : A(0, 0) {
        cout << this << " : default constuctor" << endl;
    } // 先调用初始化列表中的有参构造，再执行大括号内的默认构造
    A(int x, int y) {
        cout << this << " : param constuctor" << endl;
        this->x = x, this->y = y;
    }
    void output () {
        cout << this << " : call function" << endl;
        cout << this->x << ", " << this->y << endl;
        return ;
    }

private:
    int x, y;
};

int main() {
    A a{10, 101}, b;
    cout << "a : " << &a << endl;
    cout << "b : " << &b << endl;
    a.output();
    b.output();
    a.output();
    return 0;
}
