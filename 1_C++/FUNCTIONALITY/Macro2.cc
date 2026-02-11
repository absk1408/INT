#include <iostream>
using namespace std;

#define PRINT_SUM(a, b) ((a)+(b))

int main() {
    bool a=true;
    if (a)
        PRINT_SUM(3, 4);  // Works fine  // as it just used as a text replacement.
    else
        cout << "Else block\n";

    return 0;
}
