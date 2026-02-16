//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//class base final{
class base{
    public:
    //virtual void func() final{
    virtual void func(){
        cout<<"base"<<endl;
    }
};
class der:public base{
    public:
    void func(){
        cout<<"der"<<endl;
    }
};
int main(){
    base *b=new der;
    b->func();
    return 0;
}