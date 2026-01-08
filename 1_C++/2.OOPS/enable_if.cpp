#include <type_traits>
#include <iostream>
using namespace std;

template <typename T>
typename enable_if<is_integral<T>::value, void>::type
print(T value) {
    cout << "Integral: " << value << "\n";
}

template <typename T>
typename enable_if<!is_integral<T>::value, void>::type
print(T value) {
    cout << "Non-integral: " << value << "\n";
}

int main() {
    print(10);       // Integral
    print(3.14);     // Non-integral
}
