/*************************************************************************
	> File Name: 13.destructor.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 05:59:04 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() : data(new int[10]) {
        cout << this << " default constructor" << endl;
    }
    ~A() {
        cout << this << " destructor" << endl;
        delete[] data; // delete功能类似free
    }

private:
    int *data;
};

int main(){
    A a, *pa = new A();
    // a是自动变量，pa是用new动态申请出来的变量
    // 函数执行完系统会自动调用a的析构函数，但pa不会
    cout << "a : " << &a << endl;
    cout << "pa : " << pa << endl;
    delete pa;
    return 0;
}
