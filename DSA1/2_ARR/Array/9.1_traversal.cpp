//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
//
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    ///////////////////////
    for(auto i:arr) cout<<i<<" ";  //this "i" is integer itself.
    cout<<endl;
    /////////////////////
    for(int i=0;i<10;i++){
        cout<<*(arr+i)<<" "; //bracket is important.
    }cout<<endl;
    /////////////////////////////
    int *p=new int [10];
    for(int i=0;i<10;i++){
        cout<<p[i]<<" ";
    }cout<<endl;
    for(int i=0;i<10;i++){
        cout<<*(p+i)<<" "; 
    }cout<<endl;
    ////////////////

    return 0;
}