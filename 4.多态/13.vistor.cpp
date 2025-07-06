/*************************************************************************
	> File Name: 13.visitor.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 06 Jul 2025 07:33:42 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A;
class B;
class C;

class Base {
public:
    class IVisitor {
    public:
        virtual void visit(A *) = 0;
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
    }; 
    // 访问者类，利用this指针和虚函数实现运行时准确知道对象的类型
    // 并利用函数重载对应到要执行的功能
    virtual void Accept(IVisitor *) = 0;
    virtual ~Base() {}

    int x;
};

class A : public Base {
public:
    void Accept(IVisitor *vis) {
        // F(this); --> F(A *);
        vis->visit(this);
        return ;
    }
};
class B : public Base {
public:
    void Accept(IVisitor *vis) {
        // F(this); --> F(B *);
        vis->visit(this);
        return ;
    }
};
class C : public Base {
public:
    void Accept(IVisitor *vis) {
        // F(this); --> F(C *);
        vis->visit(this);
        return ;
    }
};

class DynamicVisitor : public Base::IVisitor {
public:
    void visit(A *obj) override {
        cout << "Class A : dynamic_cast" << endl;
        return ;
    }
    void visit(B *obj) override {
        cout << "Class B : dynamic_cast" << endl;
        return ;        
    }
    void visit(C *obj) override {
        cout << "Class C : dynamic_cast" << endl;
        return ;
    }
};

class AddVisitor : public Base::IVisitor {
public:
    void visit(A *obj) override {
        result = obj->x + 1;
        return ;
    }
    void visit(B *obj) override {
        result = obj->x + 2;
        return ;        
    }
    void visit(C *obj) override {
        result = obj->x + 3;
        return ;
    }
    int result;
}; // 增加功能只需新增访问者

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
    p->x = 1000;

    DynamicVisitor vis1;
    p->Accept(&vis1);

    AddVisitor vis2;
    p->Accept(&vis2);
    cout << "result : " << vis2.result << endl;
    return 0;
}
