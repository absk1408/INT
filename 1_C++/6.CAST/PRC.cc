 #include <iostream>
#include <typeinfo>
using namespace std;

class Base {
    virtual void dummy() {}  // Required: class must be polymorphic
};

class Derived : public Base {};
class Unrelated : public Base {};

int main() {
   
        Base* base = new Unrelated();  // Actually points to Unrelated
        Derived* d = dynamic_cast<Derived*>(base);  // ❌ Invalid cast
        if(d) cout << "Casted successfully\n";
        cout<<"failed"<<endl;
    
}