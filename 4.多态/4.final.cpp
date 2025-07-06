/*************************************************************************
	> File Name: 4.final.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 06 Jul 2025 10:54:51 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct Base {
    virtual void test() {
        cout << "Base" << endl;
        return ;
    }

};

struct A : Base {
    void test() final {
        cout << "A" << endl;
        return ;
    } // final定义当前函数是最后一个版本，严禁子类重写
};

struct B : A {
    // void test() override {
    //    cout << "B" << endl;
    //    return ;
    // }
};

int main() {
    Base *p = new B();
    p->test(); // A
    return 0;
}
