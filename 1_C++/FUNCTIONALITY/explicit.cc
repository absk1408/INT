#include <iostream>
using namespace std;

class A {
public:
    //explicit A(int x)
    A(int x) {
        cout << "Constructor called with " << x << endl;
    }
};

void func(A a,A b) {
    //int c=a+b; //error
    //cout << "Function called\n"<<c<<endl; //error
    cout << "Function called\n"<<endl;
}


int main() {
    func(10,100);  // Implicitly converts int 10 to A using A(int)
    return 0;
}
