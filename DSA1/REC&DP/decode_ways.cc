class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;

        int one = 1, two = 1; // 'two' starts as 1 to handle the first character
        for (int i = 1; i < s.length(); i++) {
            int curr = 0;
            
            if (s[i] != '0') {
                curr += one;  // Single character decoding
            }

            int value = stoi(s.substr(i - 1, 2)); // Convert two-character substring to integer
            if (value >= 10 && value <= 26) {
                curr += two;  // Two-character decoding
            }

            two = one;
            one = curr;
        }

        return one;
    }
};
