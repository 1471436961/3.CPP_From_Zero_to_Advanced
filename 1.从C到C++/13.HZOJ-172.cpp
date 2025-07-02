/*************************************************************************
	> File Name: 13.HZOJ-172.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 02 Jul 2025 09:34:28 AM CST
 ************************************************************************/

#include <iostream>
#include <set>
#include <string>
using namespace std;


int main() {
    set<string> names;
    string name;
    for (int i = 0; i < 10; i++) {
        cin >> name;
        names.insert(name);
    }
    for (auto x : names) {
        cout << x << endl;
    }
    return 0;
}
