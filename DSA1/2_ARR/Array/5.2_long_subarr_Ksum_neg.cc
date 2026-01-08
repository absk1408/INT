#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int lon_sub_any(vector<int> &v, int sum) {
    unordered_map<int, int> hm; // prefix_sum -> first index
    int curr = 0, maxlen = 0;
    for (int i = 0; i < v.size(); i++) {
        curr+=v[i];
        if(curr==sum){
            maxlen=max(maxlen,i+1);
        }
        int res=curr-sum;
        if(hm.find(res)!=hm.end()){
            maxlen=max(maxlen,(i-(hm[res])));
        }
        if(hm.find(curr)!=hm.end()) hm[curr]=i;

    }
    return maxlen;
}

int main() {
    vector<int> v = {1, -1, 5, -2, 3};
    int sum = 3;
    cout << "Longest length: " << lon_sub_any(v, sum) << endl;
    return 0;
}
