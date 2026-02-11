#include<iostream>
using namespace std;

class base {
protected:
    int a = 10;
};

class child : private base {
int b=100;
public:
    void show() {
        cout << a<<b;   // ✔ allowed here
    }
};

int main() {
    child c1;
    c1.show();      // call function that accesses protected member
}
