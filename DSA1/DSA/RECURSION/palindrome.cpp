//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
bool isPalindrome(string &s,int a,int b){
    if(a>=b) return true;
    return (s[a]==s[b])&&isPalindrome(s,a+1,b-1);
}
bool pal(string str1,int l,int r){
    if(l>=r) return true;
    else if(str1[l]!=str1[r]) return false;
    return pal(str1,l+1,r-1); //we can make it tail rec.
}
bool palindrome1(string str){
    int l=0;
    int r=str.length();
    return pal(str,l,r-1);
}
int main(){
    string s="a";
    cout<<pal(s,0,0);
    return 0;
}