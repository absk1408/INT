#include <bits/stdc++.h>
#include <vector>
#include<libxmlparser.h>
using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};
    int i = 2; // index of element to remove (removes 30)

    if (i >= 0 && i < vec.size()) {
        vec.erase(vec.begin() + i);
    }

    // Print the updated vector
    for (int val : vec) {
        cout << val << " ";
    }

    return 0;
}
