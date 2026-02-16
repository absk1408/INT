#include <iostream>
using namespace std;
//enum (enumeration) is a user-defined data type that represents a fixed set of named integer constants.
enum class color { red, green, blue, white };
enum class color2{ red, green, blue, white };

void checkPermission(color p) {
    switch (p) {
        case color::red:
            cout << "No permissions granted.\n";
            break;
        case color::blue:
            cout << "You can read the file.\n";
            break;
        case color::green:
            cout << "You can write to the file.\n";
            break;
        case color::white:
            cout << "You can execute the file.\n";
            break;
        default:
            cout << "Unknown permission.\n";
            break;
    }
}
int main() {
    color up = color::red;

    //color up =color::red; // enum calss is scoped enum
    checkPermission(up);
    return 0;
}
