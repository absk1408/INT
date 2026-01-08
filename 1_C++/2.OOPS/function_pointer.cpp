//without using virtual

//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class Base {
public:
    void (*func)();
};
void derivedFunc() {
    cout << "Derived function\n";
}

int main() {
    Base obj;
    obj.func = derivedFunc;
    obj.func();
}
