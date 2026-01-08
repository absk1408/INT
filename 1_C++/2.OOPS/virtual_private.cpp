#include <iostream>
using namespace std;

class Base {
private:
    virtual void show() {
        cout << "Base::show()" << endl;
    }
public:
    void callShow() {
        show();  // OK: called from within Base
    }
};

class Derived : public Base {
public:
    void show(){
        cout << "Derived::show()" << endl;
    }
};

int main() {
    Derived d;
    Base* b = &d;
    //b->show(); // ❌ ERROR: 'show' is private in 'Base'
    b->callShow();  // ✅ Works, and calls Derived::show()
}
