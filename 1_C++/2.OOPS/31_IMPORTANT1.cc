//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    int a;
    public:
    virtual void func(){ cout<<"base"<<endl;

    }
};
class der:private base{ //private inhertitence not allowed in polymorphism
    public:
    void func(){
        cout<<"der"<<endl;
    }
    
};
int main(){
    der d;
    base *b=&d;
    b->func();
    return 0;
}