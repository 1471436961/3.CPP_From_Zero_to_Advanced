/*************************************************************************
	> File Name: 34.shared_ptr.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Fri 20 Mar 2026 04:21:39 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
using namespace std;

#define BEGINS(x) namespace x {
#define ENDS(x) } // end of namespace x

BEGINS(test1)

class A {
public:
    A() {
        cout << "default constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
};

int main() {
    shared_ptr<A> p = make_shared<A>();
    cout << "p.use_count = " << p.use_count() << endl;
    shared_ptr<A> q = p;
    cout << "p.use_count = " << p.use_count() << endl;
    cout << "q.use_count = " << q.use_count() << endl;
    p = nullptr;
    cout << "q.use_count = " << q.use_count() << endl;
    q = nullptr;
    cout << "end main" << endl;
    return 0;
}

ENDS(test1)

BEGINS(test2)

class A {
public:
    A() {
        cout << "default constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
    
    shared_ptr<A> p;
};

int main() {
    shared_ptr<A> p = make_shared<A>();
    shared_ptr<A> q = make_shared<A>();
    p->p = q;
    q->p = p; // 环形引用
    p = nullptr;
    q = nullptr;
    cout << "end main" << endl;
    return 0;
}

ENDS(test2)

BEGINS(test3)

class A {
public:
    A() {
        cout << "A default constructor" << endl;
    }
    ~A() {
        cout << "A destructor" << endl;
    }

    int x, y;
    shared_ptr<A> p;
};

class ptr_data {
public:
    ptr_data(A *ptr, int *cnt = nullptr)
    : ptr(ptr), cnt(cnt) {
        cout << this << " : ptr_data default constructor" << endl; 
        if (cnt == nullptr) { 
            this->cnt = new int(1); 
        }
        return ;
    } 
    ptr_data(const ptr_data &obj) : ptr(obj.ptr), cnt(obj.cnt) {
        cout << this << ": ptr_data copy constructor" << endl;
        return ;
    } 
    
    void increase_one() {
        *cnt += 1;
        return ;
    }
    void decrease_one() const {
        *cnt -= 1;
        if (*cnt == 0) delete ptr;
        return ;
    }

    bool operator==(const ptr_data &p) const {
        return p.ptr == ptr && p.cnt == cnt;
    }

    ~ptr_data() {
        cout << this << " : ptr_data destructor" << endl;
    }

    A *ptr;
    int *cnt;
};

class shared_ptr {
public:
    shared_ptr(A *ptr) : p(ptr) {
        cout << this << " : shared_ptr default constructor" << endl;
    }
    shared_ptr(const shared_ptr &obj) : p(obj.p) {
        cout << this << " : shared_ptr copy constructor" << endl;
        p.increase_one();
    }

    shared_ptr &operator=(const shared_ptr &obj) {
        if (obj.p == p) return *this;
        p.decrease_one();
        p = obj.p;
        p.increase_one();
        return *this;
    }
    A *operator->() { return p.ptr; }
    A &operator*() { return *p.ptr; }

    int use_count() { return *(p.cnt); }

    ~shared_ptr() {
        cout << this << " : shared_ptr destructor" << endl;
        p.decrease_one();
    }
private:
    ptr_data p;
};

shared_ptr make_shared() {
    return shared_ptr(new A());
}

ostream &operator<<(ostream &out, const A &a) {
    out << "class A : " << a.x << ", " << a.y;
    return out;
}

int main() {
    shared_ptr p = make_shared();
    p->x = 3, p->y = 4;
    cout << *p << endl;
    cout << "p.use_count = " << p.use_count() << endl;
    shared_ptr q = p;
    cout << "p.use_count = " << p.use_count() << endl;
    cout << "q.use_count = " << q.use_count() << endl;
    p = nullptr;
    cout << "q.use_count = " << q.use_count() << endl;
    q = nullptr;
    cout << "end main" << endl;
    return 0;
}

ENDS(test3)

int main() {
    // test1::main();
    // test2::main();
    test3::main();
    return 0;
}
