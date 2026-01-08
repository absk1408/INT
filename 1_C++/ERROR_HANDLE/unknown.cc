 #include <iostream>
#include <typeinfo>
using namespace std;

class Base {
    virtual void dummy() {}  // Required: class must be polymorphic
};

class Derived : public Base {};
class Unrelated : public Base {};

int main() {
    try {
        Base* base = new Unrelated();  // Actually points to Unrelated
        Derived& d = dynamic_cast<Derived&>(*base);  // ❌ Invalid cast
        cout << "Casted successfully\n";
    } catch (const bad_cast &e) {
        cout << "Caught bad_caaaaaast: " << e.what() << endl;
    }
    //or
    catch(...){  // if thrown error is unknown.
        cout<<"caught bad_cassst"<<endl;
    }
}
