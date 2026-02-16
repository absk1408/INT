#include <iostream>
using namespace std;
//Base  -->  Derived1  -->  Derived2

class Base {
public:
    virtual void show() {
        cout << "Base show()\n";
    }

    virtual ~Base() {}   // Important!
};

class Derived1 : public Base {
public:
    void show() override {
        cout << "Derived1 show()\n";
    }
};

class Derived2 : public Derived1 {
public:
    void show() override {
        cout << "Derived2 show()\n";
    }
};

int main() {
    Base* ptr = new Derived2();   // ✔ Allowed

    ptr->show();   // Calls Derived2::show()

    delete ptr;
}
