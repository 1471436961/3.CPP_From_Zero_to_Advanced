/*************************************************************************
	> File Name: 24.method.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 10:00:49 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class People {
public:
    void say() {
        cout << "say something : " << this << endl;
        return ;
    }
    static void say2() {
        cout << "class method : say something" << endl;
        return ;
    }
};

int main() {
    People a;
    a.say();
    a.say2();
    People::say2();
    return 0;
}
