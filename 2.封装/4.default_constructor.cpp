/*************************************************************************
	> File Name: 4.defaul_constructor.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 02 Jul 2025 07:32:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "default constructor" << endl;
        x = 10, y = 100;
    }
    void output() {
        cout << "(" << x << ", " << y << ")" << endl;
        return ;
    }

private:
    int x, y;
};

int main() {
    A a; // 隐式调用默认构造
    a.output();
    A b{}; // 显式调用默认构造，但()有歧义，编译器可能会当成函数声明
    // b();
    b.output();
    return 0;
}

// A b() {
//     cout << "hello function b" << endl;
//     return A();
// }
