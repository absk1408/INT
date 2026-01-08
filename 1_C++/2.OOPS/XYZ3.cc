//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:
    int a;
    void func(){
        cout<<"im a base func"<<endl;
    }
};
class der:public base{
    public:
    void func2(){
        cout<<"im in a derv func2"<<endl;
    }
};

int main(){
    base* b2=static_cast<base*>(new der());
    b2->func2;
    
    return 0;
}