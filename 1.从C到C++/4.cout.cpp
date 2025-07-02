/*************************************************************************
	> File Name: 4.cout.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 01 Jul 2025 07:50:33 PM CST
 ************************************************************************/

#include <iostream> // input output stream
#include <iomanip> // setprecision所在的头文件
using namespace std;


int main() {
    int a = 123;
    cout << "hello world" << endl;
    cout << "a = " << a << endl;

    double b = 12.345;
    cout << b << endl;
    printf("%%lf = %lf\n", b);
    printf("%%g = %g\n", b);
    cout << setprecision(4) << b << endl; // 设置有效位数
    cout << fixed << setprecision(1) << b << endl; // fixed定点格式
    return 0;
}
