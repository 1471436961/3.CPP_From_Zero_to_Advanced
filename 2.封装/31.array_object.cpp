/*************************************************************************
	> File Name: 31.array_object.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 04 Jul 2025 04:12:21 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Array {
public:
    Array() : data(new int[10]) {}
    int &operator[](int ind) {
        return data[ind];
    } // 返回左值引用，从而贴合系统原有属性（赋值运算）
    int *data;
};

int main() {
    Array a;
    for (int i = 0; i < 10; i ++) {
        a[i] = rand() % 100;
    }
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
