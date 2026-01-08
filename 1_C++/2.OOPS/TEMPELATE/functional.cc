//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
template<typename T>
T add(T a,T b){
    return a+b;
}

//"abhishek" is const char*, we cant do operations on them. SO need to be cast manually
int main(){
    string s_res=add<string>("abhishek ","yadav");
    cout<<s_res<<endl;
    int i_res=100+200;
    cout<<i_res<<endl;
    return 0;
} 