//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class Parent{
    public:
    string a;
    public:
    virtual void getstring(string a){
        this->a=a;
        cout<<"im in a base"<<endl;
    };
    void  func(){
        cout<<"im in base"<<endl;
    }
};
class child:public Parent{
    //int a;
    void getstring(string a){ //should be same or treated diff function not a part of base
        this->a=a;
        cout<<"im in derived"<<endl;
    }
    void func(){
        cout<<"im in der"<<endl;
    }
};
int main(){
    Parent* p=new child();
    p->getstring("100");
    p->func();
    return 0;
}