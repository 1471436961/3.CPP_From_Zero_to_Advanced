/*************************************************************************
	> File Name: bind.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 27 Mar 2026 07:10:27 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

int add(int a, int b) {
    cout << "add(a, b) = ";
    return a + b;
}

void add_one(int &n) {
    n += 1;
    return ;
}

void func(int n, const char *msg) {
    cout << n << " " << msg << endl;
    return ;
}

int main() {
    auto t1 = bind(add, 3, 4);
    cout << t1() << endl;
    cout << t1() << endl;
    cout << t1() << endl;
    
    int n = 1;
    cout << "n = " << n << endl;
    auto t2 = bind(add_one, ref(n)); // ref 传引用
    t2(), t2(), t2();
    cout << "after three times t2 function call, n = "<< n << endl;

    func(3, "hello world");
    // 改变参数顺序，1, 2表示调用时候的传入的参数顺序
    auto t3 = bind(func, std::placeholders::_2, std::placeholders::_1);
    t3("hello world", 3);
    return 0;
}
