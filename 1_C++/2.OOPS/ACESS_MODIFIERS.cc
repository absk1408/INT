//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class A{
    public:
    int a=10;
    private:
    int b=101;
    protected:
    int c=1000;
    friend class B;  //to access private data memebers
};
class B:protected A{
    public:
    int d=3200;
    void func(){
        cout<<a<<" "<<b<<endl;
    }
    //friend class C;
};
class C : protected B{
    public:
    void func2(){
        cout<<a<<" "<<d<<endl;   //we cannot use b here
    }
};
int main(){
    B objb;
    objb.func();
    C obc;
    obc.func2();

    return 0;
}