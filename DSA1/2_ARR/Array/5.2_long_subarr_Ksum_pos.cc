// Longest Subarray with Sum K (All elements are positive)

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int lon_sub(vector<int>& v, int sum){
    int s = 0;
    int curr = 0;
    int maxlen = 0;

    for(int i = 0; i < v.size(); i++){
        curr += v[i];

        while(curr > sum){
            curr -= v[s];
            s++;
        }

        if(curr == sum){
            maxlen = max(maxlen, i - s + 1);
        }
    }
    return maxlen;
}

int main(){
    int n, k;
    cout << "Enter number of elements: ";
    return 0;
}
