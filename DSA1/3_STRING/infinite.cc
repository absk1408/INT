#include <iostream>
#include <cmath>
using namespace std;

int findNthDigit(int n){
    int len=1;
    int start=1;
    int m=9;
    while(n>len*m){
        n=n-(len*m);
        len++;
        start=start*10;
        m=m*10;
        
    }
    start=start+(n-1)/len;
    string s=to_string(start);
    int i=s[(n-1)%len]-'0';
    return i;


}

int main() {
    int n = 15;
    cout << "The " << n << "-th digit is: " << findNthDigit(n) << endl;  // Output: 2
    return 0;
}
