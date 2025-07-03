/*************************************************************************
	> File Name: 25.const_method.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 10:12:34 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A(int x, int y) : x(x), y(y), z(0) {}
    void output() const {
        z += 1;
        cout << x << ", " << y << ", " << z << endl;
        return ;
    }
    int x, y;
    mutable int z;
};

int main() {
    const A a(3, 4);
    a.output(); // const类型的对象只能调用const类型的方法
    a.output();
    a.output();
    a.output();
    return 0;
}
