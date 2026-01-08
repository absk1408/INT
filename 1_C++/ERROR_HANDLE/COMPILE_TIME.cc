#include <iostream>
using namespace std;

constexpr int getValue() {  //constepr make sure this get evalutated at compile time
    return 1; // Change this to a positive number to compile successfully
}

int main() {
    static_assert(getValue() > 0, "Error1 Occured"); // Compile-time check 
     //if true : no error //if false : error
    cout << "Code compiled successfully!" << endl;
    return 0;
}
