//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
int longestSubstringWithKDistinct(string str,int k){
    if(k==0) return 0;
    int res=0;
    unordered_map<char,int>hm;
    int s=0;
    for(int i=0;i<str.length();i++){
        hm[str[i]]++;
        while(hm.size()>k){
            hm[str[s]]--;
            if(hm[str[s]]==0)hm.erase(str[s]);
            s++;
        }
        res=max(res,i-s+1);
    }
    return res;
}
int main(){
    string s = "eceba";
    int k = 2;
    cout << "Longest substring with at most " << k << " distinct characters: "
         << longestSubstringWithKDistinct(s, k) << endl;
    return 0;
}