#include <iostream>
using namespace std;

string removeConsecutiveDuplicates(string str) {
    if (str.empty()) return "";
    int s=1;
    for(int i=1;i<str.length();i++){
        if(str[i]!=str[i-1]){
            str[s]=str[i];
            s++;
        }
    }
    return str.substr(0,s);
}

int main() {
    string str = "aabbccdde";
    cout << "After removing consecutive duplicates: " << removeConsecutiveDuplicates(str) << endl;
    return 0;
}
