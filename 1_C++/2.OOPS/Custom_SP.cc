#include <iostream>
using namespace std;
template <typename T>
class MySmartPointer {
private:
    T* ptr;
public:
    // Constructor
    MySmartPointer(T* p = nullptr) : ptr(p) {}

    // Destructor
    ~MySmartPointer() {
        delete ptr;
        cout << "Memory released\n";
    }

    // Overload * and -> operators
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }

    // Delete copy constructor & copy assignment to make it "unique"
    MySmartPointer(const MySmartPointer&) = delete;
    MySmartPointer& operator=(const MySmartPointer&) = delete;

    // Move constructor
    MySmartPointer(MySmartPointer&& other) {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    // Move assignment
    MySmartPointer& operator=(MySmartPointer&& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
};