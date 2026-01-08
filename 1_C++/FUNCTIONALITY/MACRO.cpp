#include <iostream>
using namespace std;

#define SQUARE(x) (x * x)  // Macro function

int main() {
    cout << "Square of 5: " << SQUARE(5) << endl;  // Becomes (5 * 5)
    cout << "Square of 3+1: " << SQUARE(3+1) << endl;  // Wrong! Expands to (3+1 * 3+1)
    return 0;
}
 //at compile time  =>preproceesor directive