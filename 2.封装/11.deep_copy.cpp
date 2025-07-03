/*************************************************************************
	> File Name: 11.deep_copy.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 11:23:22 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Array {
public:
    Array() : n(10), data(new int[n]) { // new的功能参考malloc
        for (int i = 0; i < n; i++) data[i] = 0;
    }
    Array(const Array &a) : n(a.n), data(new int[n]) {
        for (int i = 0; i < a.n; i++) {
            data[i] = a.data[i];
        }
    } // 深拷贝，对一般项分别赋值，对指针则另外申请内存并相应赋值实现符合逻辑的拷贝
    void set(int ind, int val) { data[ind] = val; }
    int size() { return n; }
    void output() {
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
        return ;
    }

private:
    int n, *data;
};

int main() {
    Array a, b = a; // 若没有拷贝构造则默认浅拷贝，简单的对各项分别赋值
    for (int i = 0 ; i < a.size(); i++) {
        a.set(i, 1);
    }
    for (int i = 0; i < b.size(); i++) {
        b.set(i, i);
    }
    a.output();
    b.output();
    a.set(5, 1001); // a和b的data相同，都是指向同一个区域的指针
    a.output();
    b.output();
    return 0;
}
