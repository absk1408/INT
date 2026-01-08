//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;

void bucketSort(int arr[],int n,int k){
    vector<int>bkt[k];
    int mx=0;
    loop(0,n) if(arr[i]>mx) mx=arr[i];
    //max_value=80;
    int d=mx/k;
    loop(0,n){
        int ans=arr[i]/d;

    }






}
//
int main(){
    const int n=7;
    int arr[7]={30,40,10,80,5,12,70};
    bucketSort(arr, n,4);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}