#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int lon_sub_any(vector<int> &v, int sum) {
    unordered_map<int, int> hm; // prefix_sum -> first index
    int curr = 0, maxlen = 0;

    for (int i = 0; i < v.size(); i++) {
        curr += v[i];

        if (curr == sum) {
            maxlen = max(maxlen, i + 1);
        }

        int rem = curr - sum;
        if (hm.find(rem) != hm.end()) {
            maxlen = max(maxlen, i - hm[rem]);
        }

        // store first occurrence only
        if (hm.find(curr) == hm.end()) {
            hm[curr] = i;
        }
    }
    return maxlen;
}

int main() {
    vector<int> v = {1, -1, 5, -2, 3};
    int sum = 3;
    cout << "Longest length: " << lon_sub_any(v, sum) << endl;
    return 0;
}
