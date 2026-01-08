#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string columnTitle) {
    int result = 0;
    for (char c : columnTitle) {
        int value = c - 'A' + 1;
        result = result * 26 + value;
    }
    return result;
}

int main() {
    string column = "CBA";
    cout << column << " -> " << titleToNumber(column) << endl; // Output: 28
    return 0;
}