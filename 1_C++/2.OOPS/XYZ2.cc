//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
 class base{
    public:
    int a;
    base(int a){
        this->a=a;
    }
    base* operator->(){
        a*=2;
        return this;
    }

 };
int main(){
    base b(99);
    cout<<b->a<<endl;
   ////
    base *b2=new base(100);
    cout<<b2->a<<endl;


}