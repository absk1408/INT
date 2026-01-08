#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string convertToTitle(int n) {
    string s="";
    while(n>0){
        n--;
        int a=n%26;
        s+=('A'+a);
        //s=s+('A'+a);
        n=n/26;
    }
    reverse(s.begin(),s.end());
    return s;

}

int main() {
    int n = 132;
    cout <<convertToTitle(n) << endl; // Output: 27 -> AA
    return 0;
}