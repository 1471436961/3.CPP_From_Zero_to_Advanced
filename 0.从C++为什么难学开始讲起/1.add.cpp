/*************************************************************************
	> File Name: 1.add.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 01 Jul 2025 05:52:39 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

// 面向过程
int add1(int a, int b) {
	return a + b;
}

// 面向对象
class ADD {
public :
	int operator()(int a, int b) const {
		return a + b;
	}
} add2;

//泛型编程
template<typename T, typename U>
auto add3(T a, U b) -> decltype(a + b) {
	return a + b;
}

// 函数式编程
auto add4 = [](int a, int b) -> int {
	return a + b;
};

// 模板元编程
template<int N, int M>
struct add5 {
	static const int r = N + M;
};

int main() {
	cout << add1(3, 4) << endl;
	cout << add2(3, 4) << endl;
	cout << add3(3, 4) << endl;
	cout << add4(3, 4) << endl;
	cout << add5<3, 4>::r << endl;
	return 0;
}
