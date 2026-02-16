//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
bool areAnagrams(string&s1, string &s2){
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return (s1==s2);
}
//usign hashmap

bool areAnagramshash(string& s1,string& s2){
    unordered_map<char,int> charCount;
    for(char ch:s1) charCount[ch]+=1;
    for(char ch:s2) charCount[ch]-=1;
    for(auto pair:charCount){
        if(pair.second!=0) return false;
    }
    return true;
}
//group anagram
void group(vector<string> & vec){
    unordered_map<string,vector<string>>m1;
    for(auto i:vec){
        string temp=i;
        sort(temp.begin(),temp.end());
        m1[temp].push_back(i);
    }
    cout<<"[";
    int count=0; //as we are using for auto for loop need to use cutome count
    for(auto x:m1){
        if(count>0) cout<<",";
        cout<<"[";
        vector<string> v2=x.second;
        int len=v2.size();
        for(int i=0;i<len;i++){
            if(i>0) cout<<",";
            cout<<x.second[i];
        }
        cout<<"]";
        count++; //have to increment manually
    }
    cout<<"]";
}

int main(){
    string s1 = "geeks";
    string s2 = "kseeg";
    //cout << (areAnagramshash(s1, s2) ? "true" : "false") << endl;
    //++++++++++++++++++++++++++++++++++++//
    vector<string> arr;
    arr.push_back("geeksquiz");
    arr.push_back("geeksforgeeks");
    arr.push_back("abcd");
    arr.push_back("forgeeksgeeks");
    arr.push_back("zuiqkeegs");
    arr.push_back("cat");
    arr.push_back("act");
    arr.push_back("tca");
    group(arr);
    return 0;
}