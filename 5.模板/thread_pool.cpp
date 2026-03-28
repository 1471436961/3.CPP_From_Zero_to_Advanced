/*************************************************************************
	> File Name: thread_pool.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 28 Mar 2026 09:39:18 PM CST
 ************************************************************************/

#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <vector>
#include <unordered_map>
#include <condition_variable>
#include <queue>
using namespace std;

#define BEGINS(x) namespace x {
#define ENDS(x) } 

BEGINS(thread_usage)

void func() {
    cout << "hello world" << endl;
    return ;
}

void print(int a, int b) {
    cout << a << " " << b << endl;
    return ;
}

int main() {
    thread t1(func); // C++ 中一切皆对象
    t1.join(); // 等待线程结束
    thread t2(print, 3, 4); // 给线程传参
    t2.join();
    return 0;
}

ENDS(thread_usage)


BEGINS(prime_count_test)

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int prime_count(int l, int r) {
    int ans = 0;
    for (int i = l; i <= r; i++) {
        ans += is_prime(i);
    }
    return ans;
} // 多线程编程中，功能函数尽量类似原子操作，不去访问全局变量

// 多线程入口函数
void worker(int l, int r, int &ret) {
    ret = prime_count(l, r);
    cout << this_thread::get_id() << " done" << endl;
    return ;
} // 多线程程序设计中，功能函数和线程入口函数分开，实现高内聚低耦合

int main() {
    #define batch 5000000
    thread *t[10];
    int ret[10];
    for (int i = 0, j = 1; i < 10; i++, j += batch) {
        t[i] = new thread(worker, j, j + batch - 1, ref(ret[i]));
    }
    for (auto x : t) x->join();
    int ans = 0;
    for (auto x : ret) ans += x;
    for (auto x : t) delete x;
    cout << ans << endl;
    return 0;
}

ENDS(prime_count_test)


BEGINS(prime_count_test1)

int ans = 0;
std::mutex m_mutex; // 互斥锁

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void prime_count(int l, int r) {
    cout << this_thread::get_id() << " begin" << endl;
    for (int i = l; i <= r; i++) {
        unique_lock<mutex> lock(m_mutex); // 上锁
        ans += is_prime(i);
        lock.unlock();
    }
    cout << this_thread::get_id() << " done" << endl;
    return ;
}

int main() {
    #define batch 5000000
    thread *t[10];
    for (int i = 0, j = 1; i < 10; i++, j += batch) {
        t[i] = new thread(prime_count, j, j + batch - 1);
    }
    for (auto x : t) x->join();
    for (auto x : t) delete x;
    cout << ans << endl;
    return 0;
}

ENDS(prime_count_tes1)


BEGINS(prime_count_test2)

int ans = 0;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void prime_count(int l, int r) {
    cout << this_thread::get_id() << " begin" << endl;
    for (int i = l; i <= r; i++) {
        int ret = is_prime(i);
        __sync_fetch_and_add(&ans, ret); // 原子操作的 += 
    }
    cout << this_thread::get_id() << " done" << endl;
    return ;
}

int main() {
    #define batch 5000000
    thread *t[10];
    for (int i = 0, j = 1; i < 10; i++, j += batch) {
        t[i] = new thread(prime_count, j, j + batch - 1);
    }
    for (auto x : t) x->join();
    for (auto x : t) delete x;
    cout << ans << endl;
    return 0;
}

ENDS(prime_count_test2)


BEGINS(task_test)

class Task {
public:
    template<typename FUNC_T, typename ...ARGS>
    Task(FUNC_T func, ARGS ...args) {
        this->func = bind(func, forward<ARGS>(args)...);
    }
    void run() {
        func();
        return ;
    }
private:
    function<void()> func;
}; // 将函数（计算过程）和参数（数据）绑定在一起

void test() {
    cout << "hello world : function test" << endl;
    return ;
}

void func(int a, int b) {
    cout << "function " << a << " " << b << endl;
    return ;
}

void add_one(int &n) {
    n += 1;
    return ;
}

int main() {
    Task t1(func, 3, 4);
    t1.run();
    t1.run();
    Task t2(test);
    t2.run();
    int n = 1;
    cout << "n = " << n << endl;
    Task t3(add_one, ref(n)); // 明确传引用
    t3.run();
    t3.run();
    t3.run();
    t3.run();
    cout << "n = " << n << endl;
    return 0;
}

ENDS(task_test)


BEGINS(thread_pool_test)

class Task {
public:
    template<typename FUNC_T, typename ...ARGS>
    Task(FUNC_T func, ARGS ...args) {
        this->func = bind(func, forward<ARGS>(args)...);
    }
    void run() {
        func();
        return ;
    }
private:
    function<void()> func;
}; // 将函数（计算过程）和参数（数据）绑定在一起

class ThreadPool {
public:
    ThreadPool(int n = 1) 
    : thread_size(n), threads(n), starting(false) {
        this->start();
        return ;
    }
    void worker() {
        auto id = this_thread::get_id();
        running[id] = true;
        while (running[id]) {
            Task *t = get_task();
            t->run();
        }
        return ;
    } // 入口函数
    
    void start() {
        if (starting == true) return ;
        for (int i = 0; i < thread_size; i++) {
            // 成员方法需要 this 指针参数
            threads[i] = new thread(&ThreadPool::worker, this);
        }
        starting = true;
        return ;
    }
    void stop() {
        if (starting == false) return ;
        for (int i = 0; i < threads.size(); i++) {
            this->add_task(&ThreadPool::stop_running, this);
        }
        for (int i = 0; i < threads.size(); i++) {
            threads[i]->join();
        }
        for (int i = 0; i < threads.size(); i++) {
            delete threads[i];
            threads[i] = nullptr;
        }
        starting = false;
        return ;
    }
    template<typename FUNC_T, typename ...ARGS>
    void add_task(FUNC_T func, ARGS ...args) {
        unique_lock<mutex> lock(m_mutex);
        tasks.push(new Task(func, forward<ARGS>(args)...));
        m_cond.notify_one();
        return ;
    }
    ~ThreadPool() {
        this->stop();
        while (!tasks.empty()) {
            delete tasks.front();
            tasks.pop();
        }
        return ;
    }

private:
    Task *get_task() {
        unique_lock<mutex> lock(m_mutex);
        while (tasks.empty()) m_cond.wait(lock); // while 循环防止虚假唤醒
        Task *t = tasks.front();
        tasks.pop();
        return t;
    }
    void stop_running() {
        auto id = this_thread::get_id();
        running[id] = false;
        return ;
    }
    
    bool starting;
    int thread_size;
    std::mutex m_mutex;
    condition_variable m_cond; // 条件信号量
    vector<thread *> threads;
    unordered_map<decltype(this_thread::get_id()), bool> running;
    queue<Task *> tasks; // 临界资源
};

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int prime_count(int l, int r) {
    int ans = 0;
    for (int i = l; i <= r; i++) {
        ans += is_prime(i);
    }
    return ans;
} // 多线程编程中，功能函数尽量类似原子操作，不去访问全局变量

// 多线程入口函数
void worker(int l, int r, int &ret) {
    cout << this_thread::get_id() << " begin" << endl;
    ret = prime_count(l, r);
    cout << this_thread::get_id() << " done" << endl;
    return ;
} // 多线程程序设计中，功能函数和线程入口函数分开，实现高内聚低耦合

int main() {
    ThreadPool tp(5);
    #define batch 5000000
    int ret[10];
    for (int i = 0, j = 1; i < 10; i++, j += batch) {
        tp.add_task(worker, j, j + batch - 1, ref(ret[i]));
    }
    tp.stop();
    int ans = 0;
    for (auto x : ret) ans += x;
    cout << ans << endl;
    return 0;
}

ENDS(thread_pool_test)

int main() {
    // thread_usage::main();
    // prime_count_test::main(); // 75.34s user 0.03s system 385% cpu 19.538 total
    // 加锁造成的系统开销巨大！
    // prime_count_test1::main(); // 76.05s user 23.27s system 124% cpu 1:19.98 total
    // prime_count_test2::main(); // 97.90s user 0.06s system 383% cpu 25.564 total
    // task_test::main();
    // 有了线程池，多线程程序设计会方便很多
    thread_pool_test::main(); // 74.92s user 0.05s system 370% cpu 20.215 total
    return 0;
}
