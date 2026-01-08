//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//move zeroes to the end;

int main(){
    int n=7;
    int arr[]={10,5,0,8,0,9,0};
    int count=0;
    for(int i=0;i<n;i++){ //two pointer.ß
        if(arr[i]!=0){
            swap(arr[i],arr[count]);
            count++;
        }
    }
/////
int arr2[]={10,5,0,8,0,9,0};
stable_partition(arr2,arr2+n,[](int x){return  x!=0;});
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<" ";
    }
    return 0;
}