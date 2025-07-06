/*************************************************************************
	> File Name: 10.reinterpret_cast.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sun 06 Jul 2025 04:31:12 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;


int main() {
    int a, b, c, d;
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    unsigned int n;
    char *p = reinterpret_cast<char *>(&n);
    p[3] = a;
    p[2] = b;
    p[1] = c;
    p[0] = d;
    printf("n = %u\n", n);
    return 0;
}
