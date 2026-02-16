//trapped water
//width=1;
//height bars: 7,0,4,2,5,0,6,4
//#include<bits/stdc++.h> 
// old method => can we resolved using pre computer array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int trapped(int arr[], int n){
    if(n < 3) return 0;

    int left[n], right[n];

    left[0] = arr[0];
    for(int i = 1; i < n; i++)
        left[i] = max(left[i-1], arr[i]);

    right[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--)
        right[i] = max(right[i+1], arr[i]);

    int res = 0;
    for(int i = 1; i < n-1; i++){
        res += min(left[i], right[i]) - arr[i];
    }

    return res;
}

int main(){
    int arr[] = {7,0,4,2,5,0,6,4,0,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << trapped(arr,n);
}
