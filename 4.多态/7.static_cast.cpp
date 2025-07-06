/*************************************************************************
	> File Name: 7.static_cast.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 06 Jul 2025 02:22:10 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

namespace T1 {
    void run() {
        int x = 123; // long long, double, float
        double fx = static_cast<double>(x);
        const int cx = 456;
        int non_cx = static_cast<int>(cx);
        return ;
    }
}

namespace T2 {
    void run() {
        // int *x = new int; // 和double * 不是同一类型的指针
        // double *fx = static_cast<double *>(x);
        // const int *cx = int(); // const int *和int * 不是同一类型的指针
        // int *non_cx = static_cast<int *>(cx);
        int * const p1 = new int();
        int * p2 = static_cast<int *>(p1);
        return ;
    }
}

namespace T3 {
    class Base {};
    class A : public Base {
    public:
        operator int() {
            return 999;
        } // 转换运算符
    };
    class B {};
    class C : public Base {};
    class D : public A {};
    void run() {
        A *p1 = new A();
        // B *p2 = static_cast<B *>(p1);
        Base *p3 = static_cast<Base *>(p1); // 存在继承关系的各类是同类的
        // C *p4 = static_cast<C *>(p1); // 兄弟类型之间不能相互转换
        D *p5 = static_cast<D *>(p3); // 存在直系继承关系的各类是同类的的
        cout << (int)(*p1) << endl; // C语言的强制类型转换调用转换运算符
        cout << static_cast<int>(*p1) << endl; // static_cast调用转换运算符 
        return ;
    }
}

int main() {
    T1::run();
    T2::run();
    T3::run();
    return 0;
}
