//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void wave(int arr[],int n){
    for(int i=1;i<n;i+=2){
        if(i>0&&arr[i-1]>arr[i]){
            swap(arr[i],arr[i-1]);
        }
        if(i<n&&arr[i]<arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
}
int main(){
    int arr[]={7,0,4,2,5,0,6,4,0,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    wave(arr,n);
    for(auto x:arr) cout<<x<<" ";
    return 0;
}