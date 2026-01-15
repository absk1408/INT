//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    int a=100;
    virtual void show(){
        cout<<"im in base"<<endl;
    }
    friend class d3;
};
class base2{
    public:
    void func(){
        cout<<"im in base2"<<endl;
    }
    virtual void show(){
        cout<<"im der3"<<endl;
    }
};
class d3:public base2{
    base b;
    
};

int main(){
    base2* b= new d3();
    b->func();
    b->show();
    return 0;
}