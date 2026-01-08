//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//class base final{
class base{
    public:
    //virtual void func() final{
    virtual void func(){
    }
};
class der:public base{
    public:
    void func(){

    }
};
int main(){
    der d;
    return 0;
}