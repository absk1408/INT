//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
//leetcode 71
#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
stack<string> st;
void forward_san(string& str){
    deque<string> dq;
    string s="/home////user/Documents/../Pictures";
    stringstream ss(s);
    string token;
    while(getline(ss,token,'/')){
        dq.push_back(token);
    }

    for(auto &x : dq){
        if(!x.empty()) cout <<x<<endl;
    }
}
void convert_str(string &str){
    string curr="";
    for(int i=1;i<str.length();i++){
        if(str[i]=='/'){
            if(curr == ".."){
                if(!st.empty()) st.pop();
                curr="";
            }
            else if(curr=="."){
                continue;
            }
            else{
                st.push(curr);
                curr="";
            }
        }
        else curr+=str[i];
    }
    
}
int main(){
    
    string s="/../";
    s+='/';
    forward_san(s);
    cout<<s<<endl;
    convert_str(s);
    stack<string> st2;
    while(!st.empty()){
        st2.push(st.top());
        st.pop();
    }
    while(!st2.empty()){
        cout<<"/"<<st2.top();
        st2.pop();
    }
    return 0;
}