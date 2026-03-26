/*************************************************************************
	> File Name: 3.template_param.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 26 Mar 2026 02:24:33 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T>
void Type(T a) {
    cout << "Type(T a) = " << a << endl;
    return ;
}

template<typename T>
void Type(T *a) {
    cout << "Type(T *a) = " << a << ", " << *a << endl;
    return ;
}

template<typename T, typename U>
T test_template_param(U a) {
    cout << "in template : a = " << a << endl;
    return 2 * a;
}

void func1(int (*func)(double)) {
    int val = func(12.3);
    cout << "in func1 : func(12.3) = " << val << endl;
    return ;
}

template<typename T>
void Print(T &a) {
    cout << a << endl;
    return ;
} // 左值引用模板

template<typename T>
void Print(T &&a) {
    cout << a << endl;
    return ;
} // 通用引用模板，既可传入左值，也可传入右值

int main() {
    int a = 122;
    double b = 12.3;
    Type(a);
    Type(b);
    int *p1 = &a;
    double *p2 = &b;
    Type(p1);
    Type(p2);

    Type<char>(a); // void Type(char a); 'z'
    Type<int>(a); // void Type(int a); 12
    Type<int>(p1); // void Type(int *a); 122
    Type<double>(p2); // void Type(double *a) 12.3

    func1(test_template_param); // 间接推导

    int val = 999;
    Print(val); // val 为左值，触发引用折叠，T -> int &
    Print(1000);
    return 0;
}
