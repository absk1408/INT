//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    int a; //size ==8
    char c;
    public:
    virtual void fun1(){
        cout<<"hey im a fun1 of  base"<<endl;
    }
    void fun2(){
        cout<<"hey im a fun2 of base"<<endl;
    }
};
class derived1:public base{
    int z;
    public:
    void fun1(){
        cout<<"hey im a fun1 of der1"<<endl;
    }
    void fun2(){
        cout<<"hey im a fun2 of der1"<<endl;
    }
    // void fun3(){
    //     cout<<"im in a fun3 of der1"<<endl;
    // }
};
int main(){
    //base b1;
    derived1 d1; //4+4+1+8
    base *b1=&d1; //4+1+8
    cout<<sizeof(*b1)<<" "<<sizeof(d1)<<endl;
    b1->fun1();
    return 0;
}