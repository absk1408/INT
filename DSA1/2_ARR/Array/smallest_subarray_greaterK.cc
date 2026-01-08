//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int smallestSubarrayWithSumGreaterThanK(vector<int> arr, int k){
    int minlen=arr.size();
    int currsum=0; int s=0;
    for(int i=0;i<arr.size();i++){
        currsum+=arr[i];
        while(currsum>k){
            minlen=min(minlen,i-s+1);
            currsum-=arr[s];s++;
        }
    }

}
int main() {
    vector<int> arr = {2, 3, 1, 2, 4, 3};
    int k = 7;
    cout << "Smallest Subarray: " << smallestSubarrayWithSumGreaterThanK(arr, k) << endl;
    return 0;
}