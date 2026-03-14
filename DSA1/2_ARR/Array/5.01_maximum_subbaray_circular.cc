#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int maxCircularSum(int arr[], int n){
    
    int total = 0;
    
    int maxSum = arr[0], currMax = arr[0];
    int minSum = arr[0], currMin = arr[0];
    
    for(int i = 0; i < n; i++){
        total += arr[i];
        
        if(i > 0){
            currMax = max(arr[i], currMax + arr[i]);
            maxSum = max(maxSum, currMax);
            
            currMin = min(arr[i], currMin + arr[i]);
            minSum = min(minSum, currMin);
        }
    }
    
    if(maxSum < 0)   // all elements negative
        return maxSum;
        
    return max(maxSum, total - minSum);
}