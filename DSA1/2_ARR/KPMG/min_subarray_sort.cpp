//#include<bits/stdc++.h>
/*Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] 
such that
sorting this subarray makes the whole array sorted.
Example: If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], 
your program should be able
to find that the subarray lies between indexes 3 and 8. */
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int min_sub(int arr[],int n){
    int l=0;
    int r=n-1;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            l=i;
            break;
        }
    }
    for(int j=n-2;j>0;j--){
        if(arr[j]>arr[j+1]){
            r=j;break;
        }
    }
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=l;i<=r;i++){
        if(arr[i]<min) min=arr[i];
    }
    for(int i=l;i<=r;i++){
        if(arr[i]>max) max=arr[i];
    }
    for(int i=0;i<l;i++){
        if(arr[i]>min){
            l=i;
            break; //important
        }
    }
    for(int i=r;i<n-1;i++){
        if(arr[i]<max){
            r=i; 
             //no break;
         
        }
    }

    return (r-l)+1;


}
//
int main(){
    int arr[]={10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60 };
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<min_sub(arr,n);
    //for(auto x:arr) cout<<x<<" ";
    return 0;
}