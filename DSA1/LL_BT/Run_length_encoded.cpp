//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void encoded(string s){
    int n=s.length();
    int count=1;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            cout<<s[i-1]<<count;
            count=1;
        }
        else count++;
    }
    cout<<s[n-1]<<count;
}
//
int main(){
    string s="wwwaaadexxxxx";
    encoded(s);
    return 0;
}