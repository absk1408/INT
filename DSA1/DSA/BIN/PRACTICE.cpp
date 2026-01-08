//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#define loop(x,n) for(int i=x;i<n;i++)
//
using namespace std;
class A{
    public:
    int a;
    A(int a){
        this->a=a;
    }
    void amb(){
        cout<<a<<endl;
    }

};
class B{

};
class C: public A{
    public:
    int c;
    C(int c){
        this->c=c;
    }
    void amb(){
        cout<<c<<endl;
    }
};
int main(){
    C par(10);
    par.amb();b


    return 0;
}é