//#include<bits/stdc++.h>
#include<iostream>
//
using namespace std;
//
int main(){
    int x=10;
    int res=1;
    while(x>0){
        res=res*x;
        x=x-1;
    }
    cout<<res<<endl;
    int count=0;
    while(res%10==0){
        count++;
        res=res/10;
    }
    cout<<count<<endl;
    return 0;
}