/*************************************************************************
	> File Name: 12.move_constructor.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 11:50:34 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class INT {
public:
    INT() : px(new int(0)) {
        cout << "INT default constructor" << endl;
    }
    INT(const INT &a) : px(new int(0)) {
        cout << "INT copy constructor" << endl;
        *px = *a.px;
    }
    void set(int x) {
        *px = x;
        return ;
    }
    int val() {
        return *px;
    }
    ~INT() {
        cout << "INT destructor" << endl;
        delete px;
    }

private:
    int *px;
};

class Array {
public:
    Array() : n(10), data((INT *)malloc(sizeof(INT) * n)) {
        cout << this << " default constructor" << endl;
        for (int i = 0; i < n; i++) {
            new(data + i) INT(); 
        }
    }
    Array(const Array &a) : n(a.n), data((INT *)malloc(sizeof(INT) * n)) { 
        // 不能用new，new自动调用默认构造会使得构造多于析构
        cout << this << " copy constructor" << endl;
        for (int i = 0; i < a.n; i++) {
            new(data + i) INT(a.data[i]); // 手动调用相应属性的构造函数
        }
    } // 拷贝构造，对左值的拷贝
    void set(int ind, int val) {data[ind].set(val);}
    void output() {
        cout << data << " : ";
        for (int i = 0; i < n; i++) {
            cout << data[i].val() << " ";
        }
        cout << endl;
        return ;
    }
    ~Array() {
        cout << this << " destructor" << endl;
        if (n == 0) return ;
        for (int i = 0; i < n; i++) {
            data[i].~INT();
        }
        free(data);
        return ;
    }

private:
    int n;
    INT *data;
};

int main() {
    Array a, b = a;
    a.set(0, 1001);
    b.set(0, 2002);
    a.output();
    b.output();
    return 0;
}
