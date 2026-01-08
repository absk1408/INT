//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<=n;i++)
//
using namespace std;
int fib(int n){
    int f[n];
    f[0]=0;f[1]=1;
    for(int i=2;i<=n;i++) f[i]=f[i-1]+f[i-2];
    loop(0,n) cout<<f[i]<<" ";
    return f[n];
}
//
int main(){
    int i=fib(10);
    return 0;
}