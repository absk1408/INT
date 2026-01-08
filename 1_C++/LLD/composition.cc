//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class A{
    int a;
    public:
    A(int a){
        this->a=a;
    }
    int get(){
        return a;
    }
};
class B{
    public:
    A* ptr;  //is-a relationship
    int b;
    B(int b):ptr(new A(b)){
        this->b=b+100;
    }
};
int main(){
    B* bptr=new B(100);
    cout<<bptr->b<<endl;
    cout<<bptr->ptr->get()<<endl;
    return 0;
}