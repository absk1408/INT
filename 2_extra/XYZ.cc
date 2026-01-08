#include <iostream>
using namespace std;

string compressString(string s) {
    if (s.empty()) return "";  // Handle empty string case properly

    string result = "";
    int count = 1;

    for (int i = 1; i < s.length(); i++) {  // Fixed initialization
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            result += s[i - 1];           // Append character
            result += to_string(count);   // Append count
            count = 1;
        }
    }

    // Append last character and its count
    result += s[s.length() - 1];  
    result += to_string(count);

    return result;
}

int main() {
    string input = "";
    cout << "Compressed: " << compressString(input) << endl;
    return 0;
}
