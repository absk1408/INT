#include <iostream>
#include <string>
using namespace std;

string longestAlternatingSubstring(string str) {
    int n = str.length();
    if (n == 0) return "";

    int maxLen = 1, currLen = 1;
    int start = 0, bestStart = 0;

    for (int i = 1; i < n; i++) {
        if (str[i] != str[i - 1]) {
            currLen++;
        } else {
            if (currLen > maxLen) {
                maxLen = currLen;
                bestStart = start;
            }
            start = i;
            currLen = 1;
        }
    }

    // Final check after the loop ends
    if (currLen > maxLen) {
        maxLen = currLen;
        bestStart = start;
    }

    return str.substr(bestStart, maxLen);
}

int main() {
    string s = "1100101";
    cout << "Longest Alternating Substring: " << longestAlternatingSubstring(s) << endl;
    return 0;
}
