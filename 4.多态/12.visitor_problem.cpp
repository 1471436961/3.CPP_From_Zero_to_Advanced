/*************************************************************************
	> File Name: 12.visitor_problem.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 06 Jul 2025 06:41:22 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Base {
public:
    virtual void output() = 0;
    virtual ~Base() {}
};

class A : public Base {
public:
    void output() override {
        cout << "Class A" << endl;
        return ;
    }
};
class B : public Base {
public:
    void output() override {
        cout << "Class B" << endl;
        return ;
    }
};
class C : public Base {
public:
    void output() override {
        cout << "Class C" << endl;
        return ;
    }
};

int main() {
    // 问题场景：
    // 1. 需要根据派生类的类型，执行不同操作
    // 2. 不希望通过增加成员方法实现此功能
    // 3. 代码维护方便，功能扩展方便
    srand(time(0));
    Base *p;
    switch (rand() % 3) {
        case 0 : p = new A(); break;
        case 1 : p = new B(); break;
        case 2 : p = new C(); break;
    }
    // type1: 调用简洁，后续修改方便，但新增功能需修改类的实现
    p->output();
    
    // type2: 不需修改类的实现，但不简洁，后续修改成本也高
    if (dynamic_cast<A *>(p) != nullptr) {
        cout << "Class A : dynamic_cast" << endl;
    }
    if (dynamic_cast<B *>(p) != nullptr) {
        cout << "Class B : dynamic_cast" << endl;
    }
    if (dynamic_cast<C *>(p) != nullptr) {
        cout << "Class C : dynamic_cast" << endl;
    }
    return 0;
}
