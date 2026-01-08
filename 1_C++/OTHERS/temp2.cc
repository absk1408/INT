//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base final{
    public:
    int a;
    base(){}
    base(int a){
        this->a=a;
    }
    virtual void func(int a) final{
        cout<<"func"<<a<<endl;
    }
   
};
int main(){
    base b(100);
    //b.func(200);
    b.func(2000);
    return 0;
}