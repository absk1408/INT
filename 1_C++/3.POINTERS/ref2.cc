#include <iostream>
using namespace std;

int* getReference() {
    static int x = 10; //make it static or else it will give error
    return &x; //wehn have to return to a pointer => pass the address
}

int main() {
    int *ref = getReference();
    *ref+=2;
    cout << *ref;
    return 0;
}
