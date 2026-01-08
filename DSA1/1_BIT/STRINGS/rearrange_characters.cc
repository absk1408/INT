//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;


int main(){
    string s="geeks";
    unordered_map<char,int> m;
    int len=s.length();
    for(int i=0;i<len;i++){
        m[s[i]]++;
    }
    vector<pair<char,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),[](const auto& a, const auto& b){return a.second<b.second;});
    string ans="";

    m.clear();
    for(auto& [key,value]:v){
        m.emplace(key,value);
    }
    for(auto i:m){
        cout<<i.first<<i.second<<endl;
    }
    char arr[len];
    int last;int skip;int pos=0;
    for(auto i:m){
        if(pos!=0){
            if(last==i.second){
                skip=1;
            }
            skip+=2;
        }
        while(i.second>0){
            if(pos<len){
                arr[pos]=i.first;
                pos+=skip;
            }
            else return -1;
        }
        last=i.second;
        
        continue;
    }
    for(int i=0;i<len;i++){
        cout<<arr[i];
    }
    return 0;
}