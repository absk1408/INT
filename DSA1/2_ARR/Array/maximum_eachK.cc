//#include<bits/stdc++.h> 
/*📌 Problem: Sliding Window Maximum
You are given an array of integers arr and an integer k.
For each contiguous subarray (window) of size k, find the maximum element in that window.*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    priority_queue<pair<int,int>> pq;
    vector<int> res;

    for(int i=0;i<nums.size();i++){
        pq.push({nums[i], i});

        while(pq.top().second <= i-k)
            pq.pop();

        if(i >= k-1)
            res.push_back(pq.top().first);
    }
    return res;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);
    for (int num : result)
        cout << num << " ";
    
    return 0;
}