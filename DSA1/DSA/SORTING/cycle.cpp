//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//
void cycle(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int item=arr[i]; int pos=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<item) pos++;
        }
        swap(item,arr[pos]);
        while(pos!=i){
            pos=i;
            for(int k=i+1;k<n;k++){
                if(arr[k]<item) pos++;
                swap(item,arr[pos]);
            }
        }

    }

}
int main(){
    int arr[]={10,20,5,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cycle(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}