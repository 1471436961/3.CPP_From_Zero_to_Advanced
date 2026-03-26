/*************************************************************************
	> File Name: 5.template_args.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 26 Mar 2026 06:59:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T>
void print(T &a) {
    cout << "left : " << a << endl;
    return ;
}

template<typename T>
void print(T &&a) {
    cout << "right : " << a << endl;
    return ;
}

template<typename T, typename ...ARGS>
void print(T &&a, ARGS &&...args) {
    cout << a << endl;
    print(std::forward<ARGS>(args)...);
    return ;
} // 利用引用折叠和 forward 实现完美转发

struct Point {
    int x, y;
};

ostream &operator<<(ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    Point p1 = {3, 4};
    print(1);
    print(12.3, "hello world"); // left，模板中字符串被推导为字符数组
    print(12.3, string("hello world")); // right，匿名对象为右值
    print("zhou", 45.6, p1);
    return 0;
}
