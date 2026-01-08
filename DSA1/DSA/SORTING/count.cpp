//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
void countS(int arr[],int n){
    int temp[100]={0};
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    for(int i=0;i<100;i++){
            while(temp[i]){
                cout<<i<<" ";
                temp[i]--;
            }
    }
}
int main(){
    const int n=6;
    int arr[n]={1,4,4,1,0,1};
    countS(arr,n);
    return 0;
}

//TC O(n+k)