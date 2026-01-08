#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(const vector<string>& v) {
    if (v.empty()) return "";
    for(int i=0;i<v[0].size();i++){
        char c=v[0][i];
        for(int j=1;j<v.size();j++){
            if(i>=v[j].size()||c!=v[j][i]){  // OR
                return v[0].substr(0,i);
            }

        }
    }
    return v[0];
}

int main() {
    vector<string> input = {"flower", "flow", "flight"};
    string lcp = longestCommonPrefix(input);
    cout << "Longest Common Prefix: \"" << lcp << "\"" << endl;
    return 0;
}
