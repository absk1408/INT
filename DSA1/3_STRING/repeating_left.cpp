//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<climits>
using namespace std;
int leftMost(string str){
    unordered_map<char,int>m;
    int mini=INT_MAX;
    for(int i=0;i<str.length();i++){
        char c=str[i];
        if(m.find(c)!=m.end()) mini=min(m[c],mini);
        else m[c]=i;
    }
    return mini;
}
int main(){
    string str = "wq23sforeeks";
    cout<<"Index of leftmost repeating character:"<<endl;
    cout<<leftMost(str)<<endl;  
    return 0;
}