/*************************************************************************
	> File Name: 1.virtual.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 06 Jul 2025 10:04:42 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void run() {
        cout << "I don't know how to run" << endl;
        return ;
    }
};

class Cat : public Animal {
public:
    void run() override {
        cout << "I can run with four legs" << endl;
        return ;
    } // override配合virtual使用，让对象准确执行自己的虚函数方法
};

int main() {
    Cat c;
    Animal *p = &c;
    c.run();
    p->run();
    return 0;
}
