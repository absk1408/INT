//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
int subsum(int* arr,int N,int sum,int ans=0,int i=0){
    if(i==N&&sum==ans) return 1;
    if(i==N&&sum!=ans) return 0;
    int a=subsum(arr,N,sum,ans+arr[i],i+1);
    int b=subsum(arr,N,sum,ans,i+1);
    return a+b;
}
int main(){
    const int n=3;
    int arr[n]={10,20,15};
    int sum=0;
    int ans=subsum(arr,n,sum);
    cout<<ans;
    return 0;
}