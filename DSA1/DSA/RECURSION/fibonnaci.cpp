//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
int fibb(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    return fibb(n-1)+fibb(n-2);
}
int main(){
    int ans=fibb(1);
    cout<<ans<<endl;
    return 0;
}   