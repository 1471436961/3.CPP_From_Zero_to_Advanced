/*************************************************************************
	> File Name: 8.HZOJ-166.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 01 Jul 2025 09:35:07 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;



int main() {
    string a, b;
    int x;
    cin >> a >> x >> b;
    cout << min((int)a.size(), 100) << endl; // min要求各数据的类型严格相等，a.size的类型为无符号整型
    a.insert(x - 1, b);
    cout << a << endl;
    cout << a.size() - a.rfind('x') << endl;
    return 0;
}
