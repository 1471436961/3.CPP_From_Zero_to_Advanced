/*************************************************************************
	> File Name: 8.inherit_permission.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 05 Jul 2025 04:15:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Base {
public:
    int public_x;

protected:
    int protected_x;

private:
    int private_x;
};

class A : public Base {
public:
    void set() {
        this->public_x = 3;
        this->protected_x = 3;
        this->private_x = 3;
        return ;
    }
};

class B : public A {
public:
    void set() {
        this->public_x = 3;
        this->protected_x = 3;
        this->private_x = 3;
        return ;
    }
};

int main() {
    A a;
    a.public_x = 3;
    a.protect_x = 3;
    a.private_x = 3;
    return 0;
}
