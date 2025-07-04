/*************************************************************************
	> File Name: 33.vector.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 04 Jul 2025 04:52:37 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class my_vector {
public:
    typedef int *iterator; // iterator是类型，具体来说是指向整型的指针
    my_vector() : n(2), data(new int[n]), tail(0) {}
    int *begin() { return data; }
    int *end() { return data + tail; } // 返回最后一个元素的下一位
    size_t size() { return tail; }
    int &operator[](int ind) { return data[ind]; }
    void push_back(int x) {
        if (tail == n) {
            expand();
        }
        data[tail++] = x;
        return ;
    }

private:
    void expand() {
        int *new_data = new int[2 * n];
        for (int i = 0; i < tail; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        cout << "expand : " << n << "->" << 2 * n << endl;
        n *= 2;
        return ;
    }
    size_t n, tail;
    int *data;
};

int main() {
    vector<int> a;
    my_vector b;

    for (int i = 0; i < 10; i++) {
        a.push_back(rand() % 100);
    }
    cout << "vector<int> a push_back done" << endl;
    for (int i = 0; i < 10; i++) {
        b.push_back(rand() % 100);
    }
    cout << "my_vector b push_back done" << endl;

    cout << "vector<int> for : ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "my_vector for : ";
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }
    cout << endl;


    for (int i = 0; i < a.size(); i++) {
        a[i] = 2 * i;
    }
    cout << "vector a update 2 * i done" << endl;
    for (int i = 0; i < b.size(); i++) {
        b[i] = 3 * i;
    }
    cout << "my_vector b update 3 * i done" << endl;

    cout << "vector<int>::iterator : ";
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++){
        int x = *iter;
        cout << x << " ";
    } // 通过迭代器遍历，iter可看成指针，只要支持此方法就支持下一种方法
    cout << endl;
    cout << "my_vector::iterator : ";
    for (my_vector::iterator iter = b.begin(); iter != b.end(); iter++){
        int x = *iter;
        cout << x << " ";
    } // 通过迭代器遍历，iter可看成指针，只要支持此方法就支持下一种方法
    cout << endl;
    
    cout << "vector<int> new for : ";
    for (int x : a) {
        cout << x << " ";
    } // C++11新增，容器a中的每一个元素依次赋值给x，可看成上一种方法的简写
    cout << endl;
    cout << "my_vector new for : ";
    for (int x : b) {
        cout << x << " ";
    } // C++11新增，容器b中的每一个元素依次赋值给x，可看成上一种方法的简写
    cout << endl;
    return 0;
}
