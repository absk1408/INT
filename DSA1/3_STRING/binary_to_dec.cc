#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
using namespace std;

int binaryToDecimal(string binary) {
    int decimal = 0;
    int n = binary.length();
    int p=0;
    for(int i=n-1;i>=0;i--){
        if(binary[i]=='1'){
            decimal+=pow(2,p);
        }
        p++;
    }
    return decimal;
}

string d2b(int n){
    string s="";
    while(n>0){
        s+=to_string(n%2);
        n=n/2;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main(){
    cout<<binaryToDecimal("00000110")<<endl;
    cout<<d2b(18);
    
}
