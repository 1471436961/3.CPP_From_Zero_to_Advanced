/*************************************************************************
	> File Name: 8.left_right_value.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 09:53:36 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define TEST(expr) { \
    cout << #expr;\
    f(expr); \
}

void g(int &x) {
    cout << "g : left value" << endl;
    return ;
}

void g(int &&x) {
    cout << "g : right value" << endl;
    return ;
}

void f(int &x) {
    cout << " is left value" << endl;
    g(x);
    return ;
} // &x左值引用，优先绑定到左值

void f(int &&x) {
    cout << " is right value" << endl;
    g(std::move(x)); // 虽然&&x是右值引用，但x却是一个可被赋值的左值
    g(std::forward<int &>(x)); // move转化为右值，forward指定左值/右值
} // &&右值引用，优先绑定到右值 

void test(const int &x) {
    cout << "test function" << endl;
    return ;
} // 若无const会报错

int main() {
    int a = 12, b = 13;
    TEST(123); //right
    TEST(12 + 3); // right
    TEST(a + b); // right, a + b会产生一个匿名变量
    TEST(a); 
    TEST(b); 
    TEST(a++); // right, 返回的是被赋值为a原来值的匿名变量
    TEST(++a); // left, 返回的是+1之后的a变量
    (++a) = 1001;
    cout << a << endl;
    test(12 + 23);
    return 0;
}
