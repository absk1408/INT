#include <iostream>
#include <string>
using namespace std;

string expandCompressedString(const string& s) {
    string res=""; int n=s.length();
    int i=0;
    while(i<n){
        char c=s[i];
        i++;
        string num="";
        while(i<n&&isdigit(s[i])){
            num+=s[i];
            i++;
        }
        int count=stoi(num);
        string temp(count,c);
        res+=temp;
    }
    return res;
}
int main() {
    string compressed = "a3b2c10d3";  // Example input
    cout << "Expanded: " << expandCompressedString(compressed) << endl;
    return 0;
}
