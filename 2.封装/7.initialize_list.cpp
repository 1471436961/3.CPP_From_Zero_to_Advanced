/*************************************************************************
	> File Name: 7.initialize_list.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 02 Jul 2025 08:56:36 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

namespace test1 {

class A {
public:
    A() : A(1, 1) {}
    A(int x, int y) : x(x), y(y) {} // 外面的x代表成员属性，里面的代表参数
    void output() {
        cout << "(" << x << ", " << y << ")" << endl;
        return ;
    }

private:
    int x, y;
};

int main() {
    A a(3, 4), b(101, 202), c;
    a.output();
    b.output();
    c.output();
    return 0;
}

} // test1

namespace test2 {

class B {
public:
    B(int x) : x(x) {
        cout << this << " : Class B constructor" << endl;
    }
    int x;
};

class A {
public:
    A() : A(1, 1) {}
    A(int z) : y(z), x(z) {
        cout << "x : " << &x << endl;
        cout << "y : " << &y << endl;
    } // 初始化列表中变量赋值的顺序是变量在类中定义的顺序
    A(int x, int y) : x(x), y(y) {}
    void output() {
        cout << "(" << x.x << ", " << y.x << ")" << endl;
        return ;
    }

private:
    B x, y;
};

int main() {
    A a(5);
    a.output();
    return 0;
}

} // test2

namespace test3 {

class B {
public:
    B() {
        cout << this << " default constructor" << endl;
    }
    B(int x) {
        cout << this << " : Class B constructor" << endl;
    }
    int x;
};

class A {
public:
    A() : A(1, 1) {}
    A(int x, int y) {
        this->x.x = x; // 先构造，再赋值，效率低
        this->y.x = y;
    } // 要使用x, y对象，就必须先构造它们，这里会隐式调用B类的默认构造
    void output() {
        cout << "(" << x.x << ", " << y.x << ")" << endl;
        return ;
    }

private:
    B x, y;
};

int main() {
    A a(3, 4);
    a.output();
    return 0;
}

} // test3

int main() {
    // test1::main();
    // test2::main();
    test3::main();
    return 0;
}
