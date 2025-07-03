/*************************************************************************
	> File Name: 17.new_delete.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 03 Jul 2025 07:26:12 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A(string msg) {
        cout << msg << " constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
};

int main() {
    A *mallo_a = (A *)malloc(sizeof(A));
    free(mallo_a);
    A *new_a = new A("new");
    delete new_a;
    return 0;
}
