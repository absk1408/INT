//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
//leetcode 71
#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
stack<string> st;
void forward_san(string& str){
    int s=1;
    for(int i=1;i<str.length();i++){
        if(str[i]=='/'&& str[s-1]=='/'){
            continue;
        }
        else{
            str[s]=str[i];
            s++;
        }
    }
    str.resize(s);
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