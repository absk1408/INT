//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//
class A{
    int a,b;
    public:
    A(int x,int y):a(x),b(y){}
};
A f(int a,int b){
    return {a,b};
}
int main(){
    //unified intitialization C++11
    int x;
    int x1{};
    int z=100;
    int z1{100};
    cout<<x<<" "<<x1<<" "<<z<<" "<<z1<<endl;

    A x=f(1,3);
    return 0;
}