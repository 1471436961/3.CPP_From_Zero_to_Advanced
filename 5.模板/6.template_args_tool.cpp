/*************************************************************************
	> File Name: 6.template_args_tool.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Thu 26 Mar 2026 07:58:48 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

template<typename T, typename ...ARGS>
struct ARGS_TOOL {
    typedef T __type; // 利用 typedef 给不确定的类型一个确定的名字
    typedef ARGS_TOOL<ARGS...> __rest;
};

template<typename T>
struct ARGS_TOOL<T> { 
    // 可以通过第2个参数是否可访问__final来限制变参列表只有两个参数
    typedef T __final;
}; // 偏特化处理递归边界

template<typename ...ARGS>
class Test {
public:
    auto operator()(
        typename ARGS_TOOL<ARGS...>::__type a, // typename 保证后面为类型 
        typename ARGS_TOOL<ARGS...>::__rest::__final b) -> decltype(a + b) {
        return a + b;
    } // 返回值后置
};

int main() {
    Test<int, double> f;
    cout << f(123, 456.7) << endl;
    return 0;
}
