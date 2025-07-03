/*************************************************************************
	> File Name: 10.copy_constructor.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 10:43:15 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() : x(0), y(1) {
        cout << this << " default constructor" << endl;
    }
    A(const A &a) : x(a.x), y(a.y) { // 若没有const，可能会出现const类型的对象绑定到非const类型的引用上的情况
        cout << this << " copy constructor" << endl;
    } // 必须传递左值引用：由于形参和引用的不同，若不传引用，则会无限调用拷贝构造
    void operator=(const A &a) {
        cout << this << " operator=" << endl;
    }
    void output() {
        cout << "("<< x << ", " << y << ")" << endl;
        return ;
    }

private:
    int x, y;
};

int main() {
    const A c;
    A a, b = c; // 拷贝构造，和赋值不一样
    b = a; // 赋值语句
    cout << "a : " << &a << endl;
    cout << "b : " << &b << endl;
    a.output();
    b.output();
    return 0;
}
