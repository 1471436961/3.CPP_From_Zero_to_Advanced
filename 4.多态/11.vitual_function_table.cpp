/*************************************************************************
	> File Name: 11.vitual_function_table.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 06 Jul 2025 05:02:25 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Base {
public:
    virtual void test1() {
        cout << "Class Base : test1" << endl;
        return ;
    }
    virtual void test2(int x) {
        cout << "Class Base : test2, " << x << endl;
        return ;
    }
};

class A : public Base {
public:
    void test1() override {
        cout << "Class A : test1" << endl;
        return ;
    }
    // void test2(A *this, int x) this指针是所有成员方法都有的一个隐藏参数
    void test2(int x) override {
        cout << this << " Class A : test2, " << x << ", " << this->y << endl;
        return ;
    }
    int y;
};

typedef void (*funcT1)();
typedef void (*funcT2)(void *, int); // 增加指针参数以匹配隐藏参数this

int main() {
    A a, a2;
    cout << "virtual table address : " << ((funcT1 **)(&a))[0] << endl;
    ((funcT1 **)(&a))[0][0](); // 通过虚函数表调用虚函数
    
    a.test2(100);
    ((funcT2 **)(&a))[0][1](&a, 100); 
    // this参数位置传哪个对象的地址就是哪个对象调用虚函数，
    // 无论前面转换的是哪个对象的地址
    // 因为同一个类的对象的虚函数表地址相同
    a.y = 123;
    a2.y = 456;
    ((funcT2 **)(&a))[0][1](&a2, 100);
    return 0;
}
