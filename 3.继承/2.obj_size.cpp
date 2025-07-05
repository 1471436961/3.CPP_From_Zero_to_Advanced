/*************************************************************************
	> File Name: 2.obj_size.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 05 Jul 2025 10:37:10 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
 
#define P(class_name) { \
    printf("class %s : %lu\n", #class_name, sizeof(class_name)); \
}

class Base {
public:
    Base() : x(0x1111111111111111LL) {}
    // 后缀LL明确告诉编译器这个数应被当作long long处理（而不是int或long）
    // 为什么要用 LL？
    //      防止溢出：没有LL的64位值，某些编译器可能会当作int处理，
    //                导致数值被截断或编译错误
    //      类型匹配：成员变量x的类型是long long，用LL
    //                确保字面量类型一致，避免隐式转换。
    long long x;
};

class A : public Base {
public:
    A() : y(0x22222222) {}
    int y;
};

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
    P(Base);
    P(A);
    A a;
    output_address(&a, sizeof(a));
    return 0;
}
