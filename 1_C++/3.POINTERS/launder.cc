#include <iostream>
using namespace std;
class base{
    public:
    int a=100;
    char c='B';
};
int main() {
    alignas(base) char c[sizeof(base)];
    base* b1 = new (c) base();   // Placement new
    b1->~base();                   // Destroy
            // Reconstruct in-place
    new (c) base{300,'Z'};
    cout << launder(b1)->a <<endl; // Defined behavior

    //it is used to access the value which is re intialized again by differnt pointer 
    //wihout this is can lead to undefined behavior

    //actually it tell the compiler that i have created the new values at same location, otherwise compiler will 
    // no way to know what.
}
