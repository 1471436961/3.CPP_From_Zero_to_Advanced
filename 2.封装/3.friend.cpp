/*************************************************************************
	> File Name: 3.friend.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 02 Jul 2025 04:56:17 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    void output() {
        cout << "Class A : " << x << ", " << y << endl;
        return ;
    }

private:
    int x, y;
    friend int main(); // 相关函数/类的声明，权限不可通过内部调用传递
    friend class B; 
};

class B {
public:
    void change(A &a) {
        a.x = 100, a.y = 200;
        return ;
    }
};

void test(A &a) { 
    // a.x = 3, a.y = 4;
    return ;
}

int main() {
    A a;
    test(a);
    a.x = 3, a.y = 4;
    a.output();

    B b;
    b.change(a);
    a.output();
    return 0;
}
