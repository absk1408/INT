//#include<bits/stdc++.h>
#include<iostream>
#include<climits>
//
using namespace std;
//
int main(){
    int arr[]={2,3,5,2,23,65,3};
    int size=sizeof(arr)/arr[0];
    int max=INT_MIN;
    int pos;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
            pos=i;
        }
    }
    cout<<pos<<endl;

    //
    return 0;
}