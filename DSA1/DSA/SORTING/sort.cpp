//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define loop(x,n) for(int i=x;i<n;i++)
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={10,20,5,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    sort(arr,arr+n);
    print(arr,n);
    sort(arr,arr+n,greater<int>());
    print(arr,n);
    vector<int>v={10,20,5,3,6};
    sort(v.begin(),v.end(),greater<int>());
    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}