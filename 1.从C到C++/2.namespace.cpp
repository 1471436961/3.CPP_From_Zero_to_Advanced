/*************************************************************************
	> File Name: 2.namespace.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 01 Jul 2025 05:58:43 PM CST
 ************************************************************************/

#include <iostream>
// using namespace std; // 为防止名称冲突，正经工程开发中不被允许 

namespace apple {

int cnt = 0;
void inc() {
	cnt += 1;
	return ;
}

}

namespace banana {

int cnt = 0;
void inc() {
	cnt += 1;
	return ;
}

}

namespace apple {
	void dec() {
		cnt -= 1;
		return ;
	}
}

namespace {
	int a = 1;
}

#define P(msg) { \
	printf("%s = %d\n", #msg, msg); \
}

int main() {
	P(a);
    std ::cout << "hello world" << std::endl;
	apple::cnt += 2;
	P(apple::cnt);
	apple::dec();
	P(apple::cnt);
	using banana::cnt; // 引入banana名称空间中的cnt变量
	cnt += 100;
	P(apple::cnt);
	P(banana::cnt);

	using namespace banana; // 将整个banana名称空间中的所有标识符全部引入进来
	inc();
	P(apple::cnt);
	P(banana::cnt);
	return 0;
}
