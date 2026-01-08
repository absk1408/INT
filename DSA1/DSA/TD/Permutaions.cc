//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<unordered_set>

using namespace std;

void print_all(string s,int ind=0){
    if(ind==s.size()-1){
        cout<<s<<" ";
        return;
    }
    for(int i=ind;i<s.size();i++){
        swap(s[i],s[ind]);
        print_all(s,ind+1);
        swap(s[i],s[ind]);
    }
  
    return;
}
int main(){
    string s="ABCD";
    print_all(s);
    
    return 0;
}