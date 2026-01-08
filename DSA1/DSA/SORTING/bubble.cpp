// tc O(n^2)
//stable
//largest reach last
//only adjacent swap allowed
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void bubble(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i+1;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}
int main(){
    const int n=4;
    int arr[n]={10,8,20,5};
    bubble(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}