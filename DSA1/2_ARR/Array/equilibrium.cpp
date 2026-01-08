//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
//
using namespace std;
int eq(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int prefix=0;
   for(int i=0;i<n;i++){
        int suffix=sum-(prefix+arr[i]);
        if(prefix==suffix) return i+1;
        prefix+=arr[i];
    }
    return -1;
}
int main(){
    const int n=6;
    int array[n]={3,4,8,-9,20,6};
    cout<<eq(array,n);


    
    return 0;
}