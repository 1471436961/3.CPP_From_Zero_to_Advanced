/*************************************************************************
	> File Name: 2.public_private.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 02 Jul 2025 04:22:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class People {
public:
    string name;
    int age;

    void say1() {
        cout << "say1 : My name is " << name << ", " << age << "years old." << endl;
        return ;
    }

private:
    string name2;
    int age2;

public:
    void say2() {
        cout << "say2 : My name is " << name << ", " << age << "years old." << endl;
        return ;
    }
};

int main() {
    People zhou;
    zhou.name = "Captain zhou";
    zhou.age = 24;
    zhou.say1();
    zhou.say2();
    return 0;
}
