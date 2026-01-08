//function overloading + template
#include <iostream>
using namespace std;
template <typename T>
void show(T value) {
    cout << "General template: " << value << endl;
}

// Specialized function template for `char*`
template <>
void show(const char* value) {
    cout << "Specialized template for char*: " << value << endl;
}
template<>
void show(double d){
    cout<<"special temp: for double"<<d<<endl;
}

int main() {
    show(10);            // Calls the general template
    show(3.14);          // Calls the general template
    const char* p="abhishek";
    show(p);       // Calls the specialized template
    double d=199.3;
    show(d);
    return 0; 
}