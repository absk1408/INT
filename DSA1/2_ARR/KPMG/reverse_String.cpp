//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void reverse(string &s,int l,int h){
    while(l<=h){
        swap(s[l],s[h]);
        l++;h--;
    }
}
void reverseWords(string &s,int n){
    int st=0;
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            reverse(s,st,i-1);
            st=i+1;
        }

    }
    reverse(s,st,n-1);
    reverse(s,0,n-1);
}

int main(){
    string s = "Welcome to Gfg saaar";
    int n=s.length();
    reverseWords(s,n);
    for (int i = 0; i < n; i++) 
        cout << s[i];
    return 0;
}
