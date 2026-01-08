//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
char extra(const string&a,const string&b){
    unordered_map<char,int>m;
    for(int i=0;i<a.length();i++){
        m[a[i]]++;
    }
    for(int i=0;i<b.length();i++){
        m[b[i]]++;
    }
    for(auto i:m){
        if(i.second==1){
            return i.first;
        }
    }
    return -1;
}
int main(){
    string a="abcd";
    string b="cadbe";
    cout<<extra(a,b);
    return 0;
}