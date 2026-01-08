//forward list implements singly LL
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<forward_list>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
//
int main(){
    forward_list<int> l;
    l.assign({10,20,30,40,10});
    forward_list<int> l2;
    l2.assign(l.begin(),l.end());
    l2.remove(10);
    for(auto i:l2) cout<<i<<" ";
    cout<<endl;
    forward_list<int>l3;
    l3.assign(10,1);
    for(auto i:l3)cout<<i<<" ";
    auto it=l3.erase_after(l3.begin());
    cout<<endl;
    for(auto i:l3)cout<<i<<" ";
    return 0;
} 