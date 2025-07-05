/*************************************************************************
	> File Name: 9.mult_inherit.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 05 Jul 2025 04:42:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Base1 {};
class Base2 {};
class A : public Base1, protected Base2 {};

class Flyable {
public:
    void fly() {
        cout << "flying in the sky" << endl;
        return ;
    }
}; // 功能的封装，不是去使用相应的对象

class Swimmable {
public:
    void swim() {
        cout << "swimming in the water" << endl;
        return ;
    }
};

class Duck : public Flyable, public Swimmable {
public:
    void quack() {
        cout << "Quack, Ga Ga Ga" << endl;
        return ;
    }
}; // 多重继承的作用主要是功能的拼装

int main() {
    Duck d;
    d.fly();
    d.swim();
    d.quack();
    return 0;
}
