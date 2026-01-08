//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n=6;
    int arr[]={40,50,50,50,60,60};
    int count=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            count++;
        }
        else{
            cout<<arr[i]<<" "<<count<<endl;
            count=1;
        }
    }
    cout<<arr[n-1]<<" "<<count<<endl;
    return 0;
}