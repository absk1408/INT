//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

class Base {
public:
    virtual Base* clone() const = 0;
    virtual void display() const = 0;
    virtual ~Base()=default;
};
class Derived : public Base {
public:
    Derived* clone() const override { return new Derived(*this); }
    void display() const override {cout << "Derived\n"; }
};
Base* createObject(const Base* obj){
    return obj->clone();
}
int main(){
    Derived derivedobj;
    Base* cloneobj=createObject(&derivedobj);
    cloneobj->display();
    delete cloneobj;
}
