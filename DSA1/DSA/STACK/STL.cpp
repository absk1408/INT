//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<stack>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
//
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.size();cout<<endl;
    cout<<s.top();cout<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}