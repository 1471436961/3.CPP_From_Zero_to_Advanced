/*************************************************************************
	> File Name: 11.map.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 01 Jul 2025 10:19:05 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;


int main() {
    map<int, int> arr1;
    arr1[10000] = 1;
    arr1[-10000] = 2;
    
    map<double, int> arr2;
    arr2[1.5] = 3;
    arr2[2.5] = 4;
    arr2[3.5] = 5;

    cout << arr1.size() <<  " " << arr2.size() << endl;

    cout << arr1[10000] << endl;
    cout << arr1[100080] << endl;
    cout << arr1.size() << " " << arr2.size() << endl;

    for (auto x : arr1) {
        cout << x.first << " " << x.second << endl;
    }
    for (auto x : arr2) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
