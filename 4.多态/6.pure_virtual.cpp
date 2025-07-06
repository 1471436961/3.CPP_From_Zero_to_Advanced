/*************************************************************************
	> File Name: 6.pure_virtual.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 06 Jul 2025 11:29:15 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Flyable {
public:
    virtual void fly() = 0;
}; // 抽象类，定义接口，规定对外展现形式，子类具体实现

class Animal {
public:
    virtual void run() = 0;
}; // 抽象类

class Cat : public Animal {
public:
    void run() override {
        cout << "I can run with four legs" << endl;
        return ;
    }
}; // 若不实现父类纯虚函数，则子类就是一个抽象类：不能定义对象的类

class Bat : public Animal, public Flyable {
public:
    void run() override {
        cout << "I can run with two legs" << endl;
        return ;
    }
    void fly() override {
        cout << "I can fly, in the sky" << endl;
        return ;
    }
};

void f1(Flyable &obj) {
    cout << "this is obj : ";
    obj.fly();
    return ;
} // 专门处理某一类；子类的地址可以隐式的转化为父类的地址

int main() {
    Cat c;
    Bat b;
    c.run();
    f1(b);
    return 0;
}
