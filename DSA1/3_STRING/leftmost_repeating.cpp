//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
//
using namespace std;
int main(){
    string s1="abhishek";
    string s2="hi";
    if(s1.find(s2)!=string::npos){
        cout<<"hey"<<endl;
    }
    cout<<(s1.find(s2));
    return 0;
}