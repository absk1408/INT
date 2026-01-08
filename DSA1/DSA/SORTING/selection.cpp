//smallest to front
//unstable
//less memeory writes but more from cycle sort
//in place
//Tc O(n^2)
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
}

int main(){
    int arr[]={10,20,5,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}