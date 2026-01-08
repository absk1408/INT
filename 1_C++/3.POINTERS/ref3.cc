//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int& getval(){
    static int x=10;
    return x;
}
int main(){
    getval()=20;
    cout<<getval()<<endl;
    //can also be used as
    int& a=getval();
    cout<<a<<endl;
    return 0;
}