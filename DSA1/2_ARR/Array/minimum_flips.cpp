//#include<bits/stdc++.h>
#include<iostream>
#include<array>
#include<algorithm> 
//
using namespace std;
void mnflips(int *arr,int n){
    int b=arr[0];
    int l=0;
    for(int i=1;i<n;i++){
        if(arr[i]!=b && l==0){
            l=i;
        }
        else if(arr[i]==b && l>0){
            cout<<"from "<<l<<" to "<<i-1<<endl;
            l=0;
        }
        else{
            continue;
        }
    }
    if(arr[n-1]!=arr[0]) cout<<"from "<<l<<"to "<<n-1; //to print last element if its a beginning.

}
//
int main(){
    const int n=12;
    int arr[n]={0,0,1,1,0,0,1,1,0,1,1,1};
    mnflips(arr,n);
    return 0;
} 