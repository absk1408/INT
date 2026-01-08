//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
class student{
    public:
    int a;
    student(int a){
        this->a=a;
    }
};
int main(){
    // map<int,student> m[100];
    // for(int i=0;i<100;i++){
        
    // }
    student s(100);
    vector<student> v;
    for(int i=0;i<99;i++){
        v.push_back(s.a);
    }
    for(int i=0;i<<9;i++){
        cout<<v[i]<<" "<<endl;
    }
    return 0;
}