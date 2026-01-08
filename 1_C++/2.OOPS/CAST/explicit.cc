#include <iostream>
using namespace std;

class MyClass {
public:
    int value;
    // Constructor with explicit keyword
    //MyClass(int x) : value(x) {}
    explicit MyClass(int x) : value(x) {}
};

void printValue(MyClass obj) {
    cout << "Value: " << obj.value << endl;
}

int main() {
    MyClass obj1(10);  // OK: Direct initialization
    printValue(obj1);  // OK

    // Without 'explicit', the following would compile (implicit conversion)
    printValue(static_cast<MyClass>(20));   //int -> obj conversion  work even with explicit

    // But with 'explicit', the following gives an error:
    // printValue(20);  // ❌ Error: Cannot convert 'int' to 'MyClass' implicitly

    // If you really want to pass an int, you must be explicit:
    printValue(MyClass(20));  // ✅ Correct with explicit conversion

    return 0;
}
