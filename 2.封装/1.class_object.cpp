/*************************************************************************
	> File Name: 1.class_object.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 02 Jul 2025 03:49:14 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Cat {};
class Dog {};
class People {
public:
    string name;
    int age;

    void say() {
        cout << "My name is " << name << ", " << age << "years old." << endl;
        return ;
    }
};

int main() {
    Cat garfiled;
    Dog odie1, odie2;
    People zhou, zhang;

    zhou.name = "Captain Zhou";
    zhou.age = 24;
    zhou.say();

    zhang.name = "Captain Zhang";
    zhang.age = 23;
    zhang.say();
    return 0;
}
