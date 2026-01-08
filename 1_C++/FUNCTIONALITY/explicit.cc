#include <iostream>
using namespace std;

class A {
public:
    //explicit A(int x)
    A(int x) {
        cout << "Constructor called with " << x << endl;
    }
};

void func(A a) {
    cout << "Function called\n";
}


int main() {
    func(10);  // Implicitly converts int 10 to A using A(int)
    return 0;
}
