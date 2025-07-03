/*************************************************************************
	> File Name: 23.property.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 09:42:51 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class People {
public:
    People() { cnt += 1; }
    string name;
    static int cnt; // 类属性的声明
    ~People() {cnt -= 1; }
};
int People::cnt = 0; // 类属性的定义

void f() {
    People a, b;
    cout << "cnt : " << People::cnt << endl; // 5
    return ;
}

int main() {
    People a, b;
    cout << "cnt : " << People::cnt << endl; // 2
    People c;
    cout << "cnt : " << People::cnt << endl; // 3
    f();
    cout << "cnt : " << People::cnt << endl; // 3;
    return 0;
}
