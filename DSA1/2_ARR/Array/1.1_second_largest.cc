//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int secl(int arr[], int n){
    int lar = arr[0];
    int res = INT_MIN;

    for(int i = 1; i < n; i++){
        if(arr[i] > lar){
            res = lar;       // previous largest becomes second largest
            lar = arr[i];    // update largest
        }
        else if(arr[i] > res && arr[i] < lar){
            res = arr[i];    // arr[i] is a candidate for second largest
        }
    }

    if(res == INT_MIN) return -1; // if no second largest exists

    return res;
}

int main(){
    
    return 0;
}