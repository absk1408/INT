//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#include<memory>


class base{
    public:
    int a;
    int b;
    base(int a,int b){
        this->a=a;
        this->b=b;
    }
    int add(){
        return a+b;
    }
    ~base(){delete this;}

};

int main(){
        //CASE 1: 
    // base* b1(new base(100,110));
    // //cout<<b1->add()<<endl;
    // base* b2;
    // b2=b1;
    // //cout<<b2->add()<<endl;
    // b2->a=500;
    // //cout<<b1->add()<<endl;
    // delete b2;
    // cout<<b1->add()<<endl;

        //CASE 2:

    shared_ptr<base> a1(new base(10,22));
    cout<<a1->add()<<endl;
    shared_ptr<base> a2;
    a2=a1;
    cout<<a1->add()<<endl;
    cout<<a2->add()<<endl;
    a2->a=100;

    cout<<a1->add()<<endl;
    cout<<a2->add()<<endl;
    cout<<a2.use_count()<<endl;\
    return 0;
    
}