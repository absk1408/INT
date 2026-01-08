//Maximum Sum Subarray of Size K (fixed)
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int maxSumSubarray(vector<int> &arr,int k){
    int maxres=0;
    int curr=0;
    for(int i=0;i<k;i++){
        curr+=arr[i];
    }
    maxres=curr;
    for(int i=k;i<arr.size();i++){
        curr=(curr-arr[i-k])+arr[i];
        maxres=max(curr,maxres);
    }
    return maxres;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Maximum Sum Subarray: " << maxSumSubarray(arr, k) << endl;
    return 0;
}