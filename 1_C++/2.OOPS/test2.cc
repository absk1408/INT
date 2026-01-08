//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:
    void func2(){
        cout<<"im in base func2"<<endl;
    }
    void func3(){
        cout<<"im in base func3"<<endl;
    }
    virtual void func(){
        cout<<"im a base func"<<endl;
    }
};
class der:public base{
    public:
    void func(){
        cout<<"im in der"<<endl;
    }
    void func3(int x){
        cout<<"im in der func3"<<endl;
    }
};
int main(){
    der *d1=new base();
    return 0;
}