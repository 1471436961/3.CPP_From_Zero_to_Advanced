/*************************************************************************
	> File Name: 1.template_function.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 26 Mar 2026 11:09:23 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
    return a + b;
}

template<typename T, typename U>
void Print(T a, U b) {
    cout << a << " " << b << endl;
    return ;
} // 多参数模板

int main() {
    // 隐式类型推导
    cout << add(3, 4) << endl;
    cout << add(3.4, 5.2) << endl;
    
    // 显示类型推导
    cout << add<double>(3, 3.4) << endl;
    
    Print(3, 'c');
    return 0;
}
