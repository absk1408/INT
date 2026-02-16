#include <iostream>
#include <algorithm>
#include <new>      // for std::bad_alloc
#include <cstdlib>  // for malloc/free

using namespace std;

class custom_new {
public:
    custom_new() = default;
    ~custom_new() = default;

    // custom operator new
    void* operator new(size_t val) {
        cout << "custom operator new called, size = " << val << endl;

        void* ptr = malloc(val);   // allocate exactly required bytes
        if (!ptr) throw bad_alloc();
        return ptr;
    }

    // matching operator delete
    void operator delete(void* ptr) {
        cout << "custom operator delete called" << endl;
        free(ptr);
    }
};

int main() {
    custom_new* ptr = new custom_new();  // calls custom operator new
    delete ptr;                           // calls custom operator delete

    int* ptr2 = new int(10);              // normal global operator new
    cout << sizeof(*ptr2) << endl;        // prints 4 (usually)

    delete ptr2;
    return 0;
}
