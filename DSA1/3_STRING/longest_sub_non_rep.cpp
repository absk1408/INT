#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int longestDistinct(string str) {
    int maxLength = 0; // Stores the maximum length of the substring
    int l = 0;         // Left boundary of the sliding window
    unordered_map<char, int> m; // Map to store the last seen position of characters

    for (int r = 0; r < str.length(); r++) { // `r` is the right boundary
        char c = str[r];
        
        // If the character is already in the map and within the current window
        if (m.find(c) != m.end() && m[c] >= l) {
            l = m[c] + 1; // Move the left boundary to the right of the last seen position
        }

        m[c] = r; // Update the last seen position of the character
        maxLength = max(maxLength, r - l + 1); // Update the maximum length
    }

    return maxLength;
}

int main() {
    string str = "abhishek"; 
    int l = longestDistinct(str); 
    cout << "The length of the longest distinct "
            "characters substring is " << l; 
    return 0;
}
