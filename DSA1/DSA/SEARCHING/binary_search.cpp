//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
int bs(int *arr,int n,int x){
    int low=0;
    int high=n-1;
    while(low<=high){
        int index=(low+high)/2;
        if(arr[index]==x) return index;
        else if(arr[index]>x) high=index-1;
        else low=index+1;
    }
    return -1;
}
int rec(int *arr,int  l,int r,int n,int x){
    if(l>r) return -1;
    int mid=(l+r)/2;
    if(arr[mid]==x) return mid;
    else if(arr[mid]>x) return rec(arr,l,mid-1,n,x);
    else return rec(arr,mid+1,n-1,n,x);
    return -1;
}
int main(){
    const int n=7;
    int arr[n]={10,20,30,40,50,60,70};
    cout<<rec(arr,0,n-1,n,30);
    return 0;
    
}   