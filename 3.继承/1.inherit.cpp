/*************************************************************************
	> File Name: 1.inherit.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 05 Jul 2025 10:00:42 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public:
    Animal() = delete;
    Animal(string name) : name(name) {}
    void say() {
        cout << "My name is " << name << endl;
        return ;
    }

protected:
    string name;
}; // protected权限表示只有当前类与其子类可以访问

class Cat : public Animal {
public:
    Cat(string name) : Animal(name) {}
    // 通过初始化列表显式调用父类的有参构造，否则会因调用默认构造报错
    void run() {
        cout << "I can run with four legs" << endl;
        return ;
    }
}; 

class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {}
    void run() {
        cout << "I can run with four legs" << endl;
        return ;
    }
};

class Bat : public Animal {
public:
    Bat(string name) : Animal(name) {}
    void fly() {
        cout << "I can fly, I am " << this->name << endl;
        return ;
    }
};

int main() {
    Cat a1("Garfield");
    Dog a2("Odie");
    Bat a3("Dracula");
    a1.say();
    a1.run();
    a2.say();
    a2.run();
    a3.say();
    a3.fly();
    return 0;
}
