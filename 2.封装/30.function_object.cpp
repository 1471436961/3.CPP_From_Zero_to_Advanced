/*************************************************************************
	> File Name: 30.function_object.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 04 Jul 2025 03:46:40 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

class ADD {
public:
    int operator()(int a, int b){
        cout << "class ADD function object : ";
        return a + b;
    }
};

int add(int a, int b) {
    cout << "add function run : ";
    return a + b;
}

class CMP {
public:
    CMP(int tag = 0) : tag(tag) {}
    bool operator()(int a, int b) {
        cout << "tag : " << tag << endl;
        return a > b;
    }
    int tag;
};

bool cmp(int a, int b) {
    return a > b;
}

void output(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return ;
}

int main() {
    ADD add2;
    cout << add(3, 4) << endl;
    cout << add2(3, 4) << endl;
    int a[10] = {4, 5, 3, 1, 9, 8, 7, 2, 6, 10};
    sort(a, a + 10, CMP(2333)); // 调用构造函数生成匿名对象
    output(a, 10);
    return 0;
}
