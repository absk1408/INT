//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;

int first(int arr[],int s,int e,int x,int n){
    if(s<0||e>=n) return -1;
    int mid=(s+e)/2;
    if(arr[mid]==x){
        if(mid-1>=0&&arr[mid-1]!=x) return mid;
        else if(mid==0) return mid;
        else first(arr,0,mid-1,x,n);
    }
    else if(arr[mid]>x) first(arr,0,mid-1,x,n);
    else first(arr,mid+1,n-1,x,n);
}
int main(){
	int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 7,8 };
	int n = sizeof(arr) / sizeof(int);

	int x = 8;
	cout<<first(arr, 0, n - 1, x, n);
	//printf("\nLast Occurrence = %d\n",
		//last(arr, 0, n - 1, x, n));
	return 0; 
}