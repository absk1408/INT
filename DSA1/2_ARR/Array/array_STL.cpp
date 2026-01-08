//#include<bits/stdc++.h>
#include<iostream>
#include<array>
//
using namespace std;
array<int,5>fun(array<int,5> &a1){
    for(auto x:a1) a1[x]=5;
    return a1;
}
//
int main(){
    array<int,5>a={1,2,3,4,5};
    array<int,5> a1=fun(a);
    for(auto x:a)cout<<x<<" ";


    return 0;
}