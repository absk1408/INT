//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:
    base(){
        cout<<"this is base"<<endl;
    }
    void print(){
        cout<<"this is base print"<<endl;
    }
    virtual void show(){
        cout<<"this is base show"<<endl;
    }
};
class derived:public base{
    public:
    derived(){
        cout<<"this is derived"<<endl;
    }
    void print(){ cout<<"this is der print"<<endl;
    }
    void show(){cout<<"this is der show"<<endl;}
};
int main(){
    base* b;
    derived d;
    b=&d;
    b->print();
    b->show();
    return 0;
}