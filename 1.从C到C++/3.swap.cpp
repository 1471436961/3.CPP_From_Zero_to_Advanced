/*************************************************************************
	> File Name: 3.swap.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 01 Jul 2025 07:16:42 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void swap(int &pa, int &pb) {
    int c = pa;
    pa = pb;
    pb = c;
    return ;
}

void inc(int &x) {
    x += 1;
    return ;
}

#define P(msg) { \
    printf("%s = %d\n", #msg, msg); \
}

int main() {
    int a = 2, b = 6;
    int &c = a; // 不是赋值，而是绑定
    P(a); P(b);
    swap(a, b);
    P(a); P(b);
    inc(a), inc(a);
    inc(b);
    P(a); P(b);
    c += 100;
    P(a); P(b); P(c);
    return 0;
}
