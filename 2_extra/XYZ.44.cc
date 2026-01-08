//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class A{
    public:
    int a;
    A(int a){
        this->a=a;
    }
};

void func(A obj){
    cout<<obj.a<<endl;
}

int main(){
    int a=100;
    int *p =&a;
    int &ref=*p;
    cout<<ref<<endl;
    ref=2000;
    cout<<ref<<endl;
    cout<<a<<endl;
    int &ref2=100;
}