//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> arr,int k){
    vector<int>res; deque<int> dq;
    for(int i=0;i<k;i++){
        while(!dq.empty()&&arr[dq.back()]<=arr[i]) dq.pop_back();
        dq.push_back(i);
    }
    for(int i=k;i<arr.size();i++){
        res.push_back(arr[dq.front()]);
        if(!dq.empty()&&dq.front()<=i-k) dq.pop_front();
        while(!dq.empty()&&dq.front()<arr[i]) dq.pop_back();
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
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