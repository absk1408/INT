#include <iostream>
using namespace std;

class A;  // forward declaration

class B {
public:
    virtual void show(A& obj); // declare
};

class D : public B {
public:
    void show(A& obj) override;  // declare override
};

class A {
private:
    int secret = 42;

public:

    friend void B::show(A& obj);
    friend void D::show(A& obj);
};

void B::show(A& obj) {
    cout << "Base accessing A's secret = " << obj.secret << endl;
}

void D::show(A& obj) {
    cout << "Derived accessing A's secret = " << obj.secret << endl;
}

int main() {
    A a;
    B* ptr;

    B b;
    D d;

    ptr = &b;
    ptr->show(a);  // Base

    ptr = &d;
    ptr->show(a);  // Derived

    return 0;
}
