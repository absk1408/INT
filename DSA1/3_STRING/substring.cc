//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<climits>
using namespace std;
void findO(string & s){
    int c=INT_MAX;
    for(int i=s.length()-1;i>=0;i--){
        int d=s[i]-'0';
        if(d%2==0){
            c=i;break;
        }
    }
    cout<<s.substr(0,c+1);
    stable_partition(s.begin(),s.end(),[](char c) {return c!='0';});
}
//
int main(){
    string s="0214638";
    findO(s);
    return 0;
}