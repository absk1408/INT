
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include<vector>
#include<algorithm>
using namespace std;

string rearrangeString(const string& s){
   
    unordered_map<char,int> hm;
    for(auto x:s){
        hm[x]++;
    }
    vector<pair<char,int>>vec(hm.begin(),hm.end());
    sort(vec.begin(),vec.end(),[](auto& x,auto&y){return x.second>y.second;});
      for(auto x:vec){
        cout<<x.first<<" "<<x.second<<endl;
    }
    
    
}

int main() {
    string s = "aaabbc";
    cout << rearrangeString(s) << endl;  // e.g., "ababac"
    return 0;
}
