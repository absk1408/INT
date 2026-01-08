#include <iostream>
#include <algorithm>
using namespace std;
void first(string & s){
    sort(s.begin(),s.end());
}

bool nextPermutation(string &s) {
    int n=s.length();
    int i;
    for(i=n-2;i>=0;i--){
        if(s[i]<s[i+1]){
            break;
        }
    }

    if(i<0){
        reverse(s.begin(),s.end());
        return 0;
    }
    int curr=n-1;
    for(curr;curr>i;curr--){
        if(s[curr]>s[i]) break;
    }
    swap(s[i],s[curr]);
    reverse(s.begin()+i+1,s.end());
    return 1;

}

int main() {
    string s = "bcda";
    if (nextPermutation(s)) {
        cout << "Next permutation: " << s << endl;
    } else {
        cout << "No greater permutation exists, smallest permutation: " << s << endl;
    }
    return 0;
}
