//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void powerset(string & s){
    int n=s.length();
    int tot=1<<n;
    for(int i=0;i<tot;i++){
        for(int j=0;j<n;j++){
            if((i&(1<<j))!=0){
                cout<<s[j];
            }
        }
        cout<<endl;
    }
}
int main(){
    string s="ABC";
    powerset(s);
    return 0;
}