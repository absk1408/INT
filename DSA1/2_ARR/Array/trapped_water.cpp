//trapped water
//width=1;
//height bars: 7,0,4,2,5,0,6,4
//#include<bits/stdc++.h> 
// old method => can we resolved using pre computer array
#include<iostream>
#include<algorithm>
using namespace std;
int trapped(int arr[],int n){
    int res=0;
    if(n<3) return res;
    for(int i=1;i<n-1;i++){
        int lmax=arr[i];
        int rmax=arr[i];
        for(int j=0;j<i;j++) lmax=max(lmax,arr[j]);
        for(int k=i+1;k<n;k++) rmax=max(rmax,arr[k]);
        res+=(min(lmax,rmax)-arr[i]);
    }
    return res;
}
int main(){
    int arr[]={7,0,4,2,5,0,6,4,0,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<trapped(arr,n);
    return 0;
}