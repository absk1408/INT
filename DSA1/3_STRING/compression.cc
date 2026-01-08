//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
string compressString(string s){
    if(s.empty()) return "";
    int count=1;
    string result="";
    int i=1;
    for(i;i<s.length();i++){
        if(s[i]==s[i-1]){
            count++;
        }
        else{
            result+=s[i-1]+to_string(count);
            count=1;
        }
    }
    result+=s[i-1]+to_string(count);
    return result;
}
int main() {
    string input = "aaaabbbcccdd";
    cout << "Compressed: " << compressString(input) << endl;
    return 0;
}