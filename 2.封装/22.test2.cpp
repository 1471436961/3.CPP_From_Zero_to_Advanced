/*************************************************************************
	> File Name: 21.test.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 09:20:24 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "constructor" << endl;
    }
    void destroy() {
        delete this;
        return ;
    } // 类外不能调用析构，就在类里面调用

private: // 将析构函数设置为私有，使得类外不能调用
    ~A() {
        cout << "destructor" << endl;
    }
    friend void function_test(); // 通过友元函数实现只能在特定函数中被自动创建的对象
};

void function_test() {
    A a;
    return ;
}

int main() {
    A *pa = new A(); // new只要可以访问构造函数就可以通过编译
    pa->destroy();
    function_test();
    return 0;
}
