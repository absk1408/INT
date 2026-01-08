//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
void decrease(int arr[],int n,int i,int x){
    arr[i]=x;
    int p=(i-1)/2;
    while(i>=0&&arr[p]>arr[i]){
        int temp=arr[i];
        arr[i]=arr[p];
        arr[p]=temp;
        i=(i-1)/2;
        p=(i-1)/2;
    }
}

int main(){
    const int n=6;
    //int arr[n]={40,20,30,35,25,80,32,100,70,60};
    int arr[n]={10,20,40,80,100,70};
    decrease(arr,n,3,5);
    loop(0,n) cout<<arr[i]<<" ";
    return 0;
}