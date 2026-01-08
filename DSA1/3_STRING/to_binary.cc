#include <iostream>
#include <string>
using namespace std;

string decimalToBinary(int n) {
    string binary = "";
    while(n>0){
        int t=n%2;
        binary=to_string(t)+binary;
        n=n/2;
    }
    return binary;
}
int main(){
    cout<<decimalToBinary(18);
}