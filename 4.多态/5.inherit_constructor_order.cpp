/*************************************************************************
	> File Name: 5.inherit_constructor_order.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 05 Jul 2025 02:19:59 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor" << endl;
    }
    virtual ~Base() {
        cout << "Base destructor" << endl;
    } // 将父类析构函数改为虚函数，确保子类析构时调用的是自己的析构函数
};

class A : public Base { 
public:
    A() {
        data = new int[10];
        cout << "A constructor, data : " << data << endl;
    }
    ~A() override {
        if (data != nullptr) delete[] data;
        cout << "A destructor, data done" << endl;
    }
    int *data;
};

class B : public Base {
public:
    B() {
        cout << "B constructor" << endl;
    }
    ~B() override {
        cout << "B destructor" << endl;
    }
};

class C : public Base {
public:
    C() {
        cout << "C constructor" << endl;
    }
    ~C() override {
        cout << "C destructor" << endl;
    }
};

void func1() {
    cout << "func1 : " << endl;
    A a;
    return ;
}

void func2() {
    cout << "func2 : " << endl;
    Base *p = new A(); // 父类指针指向子类对象
    delete (A *)p; 
    // 若不改为指向子类的指针，会只调用父类析构函数造成bug，但此方法不好
    return ;
}

void func3() {
    cout << "func3 : " << endl;
    Base *p;
    switch (rand() % 3) {
        case 0: p = new A(); break;
        case 1: p = new B(); break;
        case 2: p = new C(); break;
    } 
    delete p; // ??????
    return ;
}

int main() {
    srand(time(0));
    // func1();
    // func2();
    func3();
    return 0;
}
