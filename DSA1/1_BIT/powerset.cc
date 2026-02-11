#include <iostream>
using namespace std;

void powerSet(string str) {
    int n = str.length();
    int p = 1 << n;   // 2^n subsets

    for (int i = 0; i < p; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                s += str[j];
            }
        }
        cout << s << endl;
    }
}

int main() {
    string str = "abc";
    powerSet(str);
    return 0;
}
