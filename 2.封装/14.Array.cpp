/*************************************************************************
	> File Name: 12.move_constructor.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 11:50:34 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Array {
public:
    Array() : n(10), data(new int[n]) { // new的功能参考malloc
        cout << this << " default constructor" << endl;
        for (int i = 0; i < n; i++) data[i] = 0;
    }
    Array(const Array &a) : n(a.n), data(new int[n]) {
        cout << this << " copy constructor" << endl;
        for (int i = 0; i < a.n; i++) {
            data[i] = a.data[i];
        }
    } // 拷贝构造，对左值的拷贝
    Array(Array &&a) : n(a.n), data(a.data) {
        cout << this << " move constructor" << endl;
        a.n = 0;
        a.data = nullptr;
    } // 移动构造，把右值引用赋值给新对象，避免冗余的拷贝
    Array duplicate() {
        return Array(*this); // 调用拷贝构造
    }
    ~Array() {
        cout << this << " destructor" << endl;
        if (n == 0) return ;
        delete[] data;
        return ;
    }

private:
    int n, *data;
};

int main() {
    // C++17 强制要求某些情况下的拷贝省略，
    // 即使关闭 -fno-elide-constructors，某些拷贝仍可能被优化。
    // 要看到调用移动构造，编译时需指定C++11标准
    Array a, b = a.duplicate();
    Array c;
    cout << "a : " << &a << endl;
    cout << "b : " << &b << endl;
    Array d = std::move(c); // 将c转换为右值引用从而调用移动构造
    return 0;
}
