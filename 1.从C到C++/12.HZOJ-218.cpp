/*************************************************************************
	> File Name: 12.HZOJ-218.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 02 Jul 2025 09:04:40 AM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main() {
    map<int, vector<int>> arr;
    int n;
    cin >> n;
    for (int i = 1, h; i <= n; i++) {
        cin >> h;
        arr[h].push_back(i);
    }
    int flag = 0;
    for (auto x : arr) {
        for (auto y : x.second) {
            if (flag) cout << " ";
            cout << y;
            flag = 1;
        }
    }
    cout << endl;
    return 0;
}
