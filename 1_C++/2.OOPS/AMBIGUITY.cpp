//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class A{
    public:
    A(){
        cout<<"this is a"<<endl;
    }
    void hey(){cout<<"this is A hey"<<endl;}
};
class B{
    public:
    B(){
        cout<<"this is b"<<endl;
    }
    void hey(){
        cout<<"this is B hey "<<endl;
    }
};
class C:public A,public B{
    public:
};
int main(){
    C c1;
    //c1.hey(); error cause ambiguity
    c1.A::hey(); //both funtion will run , but only one of them  run common function
    return 0;
}