/*************************************************************************
	> File Name: 4.subclass_storage.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 05 Jul 2025 11:44:56 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Base1 {
public:
    Base1() : b1(0x11111111) {}
    int b1;
};

class Base2 {
public:
    Base2() : b2(0x22222222) {}
    int b2;
};

class A : public Base2, public Base1 {
public:
    A() : a(0x33333333) {}
    int a;
}; // 父类和父类之间的存储顺序取决于继承顺序

class B : public Base1, public A {
public:
    B() : x(0x44444444) {}
    int x;
}; // 存储顺序：Base1, A(Base2, Base1), B

void output_address(void *_p, size_t n) {
    unsigned char *p = (unsigned char *)(_p);
    // 改变指针类型以便输出每个字节的内容
    printf("%p : ", p);
    for (int i = 0; i < n; i++) {
        if (i % 8 == 0) printf("\n");
        printf("%02X ", p[i]);
    }
    printf("\n");
    return ;
}

int main() {
    A a;
    output_address(&a, sizeof(a));
    B b;
    output_address(&b, sizeof(b));
    return 0;
}
