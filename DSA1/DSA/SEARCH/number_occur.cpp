//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define loop(x,n) for(int i=x;i<n;i++)
int occur(int arr[],int s,int e,int x,int n){
    if(s>e)return -1;
    int mid=(s+e)/2;
    if(arr[mid]>x) return occur(arr,0,mid-1,x,n);
    else if(arr[mid]<x)return occur(arr,mid+1,n-1,x,n);
    else {
        if(mid-1==0||mid+1==n-1)  mid;
        if(arr[mid-1]==x) return occur(arr,0,mid-1,x,n);
        if(arr[mid+1]==x) return occur(arr,mid+1,n-1,x,n);
        else{
            cout<<mid;
            return mid;
        }
    }
}
using namespace std;
//
int main(){
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
	int n = sizeof(arr) / sizeof(int);

	int x = 2;
	occur(arr, 0,n-1,x, n);

	return 0;
}