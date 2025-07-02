/*************************************************************************
	> File Name: 10.HZOJ-167.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 01 Jul 2025 09:53:23 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;


int main() {
    string a, b;
    int x;
    cin >> a >> x >> b;
    cout << a.size() << endl;
    cout << a.find('a') + 1 << endl;
    a.insert(x-1, b);
    cout << a << endl;
    return 0;
}
