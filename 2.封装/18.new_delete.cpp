/*************************************************************************
	> File Name: 18.new_delete.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 07:39:52 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A() = default;
    A(int ) : type("A(int)") {
        cout << "int constructor" << endl;
    }
    A(double ) : type("A(double)") {
        cout << "double constructor" << endl;
    }
    A(int, int) : type("A(int, int)") {
        cout << "int, int constructor" << endl;
    }
    ~A() {
        cout << type << "destructor" << endl;
    }
    string type;
};

int main() {
    int *p1 = new int;
    int *p2 = new int(100); // 申请分配存储空间的同时赋初值
    int *p3 = new int[100]; // 申请分配连续的内存空间
    cout << p1 << " sizeof(*p1) = " << sizeof(*p1) << endl;
    cout << p2 << " *p2 = " << *p2 << endl;
    for (int i = 0; i < 100; i++) {
        p3[i] = i + 1;
    }
    for (int i = 0; i < 100; i++) {
        cout << p3[i] << " ";
    }
    cout << endl;

    delete p1;
    delete p2;
    delete[] p3;

    A *a1 = new A(123);
    A *a2 = new A(12.3);
    A *a3 = new A(1, 2);

    delete a1;
    delete a2;
    delete a3;

    A *arr = new A[100]; // 会分别调用默认构造
    delete[] arr;
    return 0;
}
