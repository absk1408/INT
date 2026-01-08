//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
void minheapify(int arr[],int n,int i=0){
    int l,r,min_c=0;
    l=2*i+1;
    r=2*i+2;
    if(l<n&&arr[i]>arr[l]) min_c=l;
    else if(r<n&&arr[r]<arr[l]) min_c=r;
    else return;
    /*if(2*i+1>=n)return;
    if(arr[i]<=arr[l]&&arr[i]<=arr[r]) return;
    int min_c;
    if(arr[l]>arr[r]) min_c=r;
    else{
        min_c=l;
    } */
    //swap
    int temp=arr[min_c];
    arr[min_c]=arr[i];
    arr[i]=arr[temp];
    minheapify(arr,n,min_c);
}
int main(){
    const int n=10;
    int arr[n]={40,20,30,35,25,80,32,100,70,60};
    minheapify(arr,n);
    loop(0,n) cout<<arr[i]<<" ";
    return 0;
}