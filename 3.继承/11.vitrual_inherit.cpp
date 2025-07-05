/*************************************************************************
	> File Name: 11.vitrual_inherit.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 05 Jul 2025 05:18:35 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

bool is_little() {
    static int n = 1;
    return ((unsigned char *)&n)[0] == 1;
}

void reverse_ptr(uintptr_t &ptr) {
    unsigned char *p1 = (unsigned char *)(&ptr);
    unsigned char *p2 = p1 + sizeof(uintptr_t) -1;
    while (p1 < p2) {
        swap(p1[0], p2[0]);
        p1 ++, p2--;
    }
    return ;
}

void print_address(uintptr_t ptr, int n) {
    unsigned char *p = (unsigned char *)(ptr);
    printf("address %p : \n", p);
    for (int i = 0, j = 1; i < n; i++, j++) {
        printf("%02X", p[i]);
        // if (j % 4 == 0) printf(" "); 
        if (j % 8 == 0 && i != n - 1) printf("\n"); 
    }
    printf("\n");
} // uintptr_t标准的指针类型，会根据环境设置指针类型的大小

class A {
public:
    A() {
        this->x = 0xaaaaaaaa;
    }
    int x;
};

class B : virtual public A {
public:
    B() {
        this->y1 = 0xbbbbbbbb;
    }
    int y1;
    void set_x(int x) {
        this->x = x;
        return ;
    }
}; // 虚继承，同属父类的字段会进行合并

class C : virtual public A {
public:
    C() {
        this->y2 = 0xcccccccc;
    }
    int y2;
    int get_x() { return this->x; }
};

class D : public B, public C {
public:
    D() {
        this->z = 0xdddddddd;
    }
    int z;
};

int main() {
    if (is_little()) {
        cout << "is little" << endl;
    }
    D d;
    print_address((uintptr_t)&d, sizeof(D));
    uintptr_t ptr;
    int n;
    while (~scanf("%lx%d", &ptr, &n)) {
        if (is_little()) reverse_ptr(ptr);
        print_address(ptr, n);
    }
    return 0;
}
