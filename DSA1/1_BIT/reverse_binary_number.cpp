//reverse a binary number
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//
int main(){
    int n=12;
    int reverse=0;
    while(n>0){
        int res=n&1;
        reverse=reverse<<1; 
        reverse=reverse|res; //reverse=(reverse<<=1) | (n&1);
        n=n>>1; //n>>=1;
    }
    cout<<reverse;
    return 0;
}