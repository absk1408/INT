//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
//
using namespace std;
void insertion(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        for(j;j>=0;j--){
            if(arr[j]>key){
                arr[j+1]=arr[j];
            }
            else break; //important
        }
        arr[j+1]=key;
    }
}
int main() {
    const int n = 6;
    int arr[n] = {20, 5, 40, 60, 10, 30};
    
    // Perform insertion sort
    insertion(arr, n);
    
    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}