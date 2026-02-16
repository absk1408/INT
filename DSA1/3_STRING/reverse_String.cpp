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
void reverseWords(string &str,int n){
    int s=0;
    for(int i=0;i<n;i++){
        if(str[i]==' '){
            reverse(str,s,i-1);
            s=i+1;
        }

    }
    reverse(str,s,n-1);
    reverse(str,0,n-1);
}

int main(){
    string s = "Welcome to Gfg saaar";
    int n=s.length();
    reverseWords(s,n);
    for (int i = 0; i < n; i++) 
        cout << s[i];
    return 0;
}
