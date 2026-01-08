//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:
    int a;
    virtual void func(){
        cout<<"im in base"<<endl;
    }
    void func2(int a){
        cout<<"im in base func2"<<endl;
    } 
};
class der: public base{ 
    public:
    using base::func2;
    int b;
    void func(){
        cout<<"im in der"<<endl;
    }
    void func2(){
        cout<<"im in der func2"<<endl;
    }
};
int main(){
    der d;
    int a=100;
    d.func2(a);


    

    
}