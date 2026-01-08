#include <iostream>
using namespace std;

union Data {
    int i;
    float f;
    char c;
};
 //keep defining keep using 
int main() {
    Data d;
    
    d.i = 42;
    cout << "Integer: " << d.i << endl;  // Output: 42

    d.f = 3.14;
    cout << "Float: " << d.f << endl;    // Output: 3.14
    cout << "char: " << d.c << endl;
    cout << "Integer after float assignment: " << d.i << endl;  // ❌ Undefined behavior!

    return 0;
}
