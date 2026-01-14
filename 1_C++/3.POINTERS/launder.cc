#include <iostream>
using namespace std;
class base{
    public:
    int a=100;
    char c='B';
};
int main() {
    alignas(base) char c1[sizeof(base)];
    base* b1 = new (c1) base();   // Placement new
    b1->~base();                   // Destroy
            // Reconstruct in-place
    new (c1) base{300,'Z'};
    cout << launder(b1)->a <<endl; // Defined behavior

    //std::launder is used to safely access a new object that was created in the same memory after 
    //the previous object was destroyed. Without it, accessing the object through an old pointer may result 
    //in undefined behavior due to compiler optimizations.

    //actually it tell the compiler that i have created the new values at same location, otherwise compiler will 
    // no way to know what.
}
