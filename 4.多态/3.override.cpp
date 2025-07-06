/*************************************************************************
	> File Name: 3.override.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 06 Jul 2025 10:37:23 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct Base {
    virtual void test() {
        cout << "Base class test" << endl;
        return ;
    }
    virtual void foo() {
        cout << "Base class foo" << endl;
        return ;
    }
};

struct A : Base {
    void test() {
        cout << "A class test" << endl;
        return ;
    }
    void foo() override {
        cout << "A class foo" << endl;
        return ;
    } // override的作用不是实现功能，而是代码检查，避免类似拼写错误的情况
}; // struct默认是继承权限就是public

int main() {
    Base *p = new A();
    p->test();
    p->foo();
    return 0;
}
