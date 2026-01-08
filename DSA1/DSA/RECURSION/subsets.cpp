//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
void sub(string S,int i=0,string curr=""){
    int n=S.length();
    if(i==n){
        cout<<curr<<endl;
        return;
    }
    sub(S,i+1,curr+S[i]);
    sub(S,i+1,curr);
    
}
int main(){
    string str="abc";
    sub(str);
    return 0;
}