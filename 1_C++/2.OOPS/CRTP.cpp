// Curiously Recurring Template Pattern (CRTP)
// The Curiously Recurring Template Pattern (CRTP) is a C++ template metaprogramming technique 
// that allows a base class to call derived class function at compile time. 
// This can be useful for implementing generic algorithms, policy-based design, and other advanced C++ techniques.
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
template <typename T>
class Base {
public:
    void interface() {
        cout<<"base interface called"<<endl;
        static_cast<T*>(this)->implementation();
    }
};
class Derived : public Base<Derived> {
public:
    void implementation() {
        cout << "Derived implementation\n";
    }
};
int main() {
    Derived obj;
    obj.interface(); // Calls Derived's implementation
    obj.implementation();
}
