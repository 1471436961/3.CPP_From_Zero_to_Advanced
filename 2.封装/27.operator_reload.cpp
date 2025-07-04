/*************************************************************************
	> File Name: 27.operator_reload.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 04 Jul 2025 01:59:25 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A(int x, int y) : x(x), y(y) {}
    void output() {
        cout << "(" << x << ", " << y << ")" <<  endl;
        return ;
    }
    A &operator*=(int c) {
        x *= c, y *= c;
        return *this;
    } // 返回当前对象使其贴合系统原有运算符的属性（原有返回值是左值）
    int x, y;
};

A operator+(A a, A b) {
    return A(a.x + b.x, a.y + b.y);
}

ostream &operator<<(ostream &out, const A &a) {
    out << "operator<< : (" << a.x << ", " << a.y << ")";
    return out; // 输入out，输出out
} // const是为了兼容传入const类型的场景，传引用是为了减少一次拷贝操作

int main() {
    A a(3, 4), b(7, 10);
    A c = a + b;
    cout << c << " : end" << endl;
    c *= 3;
    cout << c << endl;
    int n = 2;
    (n *= 3) *= 4;
    cout << "n = " << n << endl;
    (c *= 2) *= 2;
    cout << c << endl;
    return 0;
}
