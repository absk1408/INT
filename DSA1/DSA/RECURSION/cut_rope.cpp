//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
int cut(int a,int b,int c,int n){
    if(n==0) return 0;
    if(n<0) return -1;
    int sum1=cut(a,b,c,n-a);
    int sum2=cut(a,b,c,n-b);
    int sum3=cut(a,b,c,n-c);
    
   
    if(sum1>sum2){
        if(sum1>sum3) return 1+sum1;  //TBD
    }
    else if(sum2>sum3) return 1+sum2;
    return 1+sum3;
}

int main(){
    cout<<cut(10,11,3,17);
    return 0;
}