// count number of ones;
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//
int main(){
    int n=0;
    int count =0;
    while(n>0){
        int res=n&1;
        if(res) count++;
        n>>=1;
    }
    cout<<count;

    return 0;
}