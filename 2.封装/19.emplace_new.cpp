/*************************************************************************
	> File Name: 19.emplace_new.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 08:04:43 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() = delete;
    A(int x) : x(x) {
        data = new int[10];
        cout << "constructor" << endl;
    }
    void output() {
        cout << "x : " << x << endl;
    }
    ~A() {
        cout << "destructor" << endl;
        delete[] data;
    }
    int x, *data;
};

int main() {
    A *arr = (A *)malloc(sizeof(A) * 5); // 先申请空间
    for (int i = 0; i < 5; i++) {
        new(arr + i) A(i); // 原地构造：在指定地址上构造
    } // 再构造
    for (int i = 0; i < 5; i++) {
        arr[i].output();
    }
    for (int i = 0; i < 5; i++) {
        arr[i].~A(); // 不能直接用delete，因为delete只能配合new运算符使用
    }
    free(arr); // 只free则只会释放存储空间，不会调用析构函数，可能会造成内存泄漏
    return 0;
}
