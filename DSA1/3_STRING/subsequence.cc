//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
bool check(string &s1,string &s2){
    int n=s1.length();
    int m=s2.length();
    int i=0,j=0;
    while(i<n&&j<m){
        if(s1[i]==s2[j]) i++;
        j++;
    }
    return i==n;
}
int main(){
    string s2="geeksforgeeksa";
    string s1="grges";
    cout<<boolalpha<<check(s1,s2);
    return 0;
}