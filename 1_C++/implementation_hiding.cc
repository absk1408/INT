//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:
    void func(int a){
        cout<<"base func"<<endl;
    }
    void func(string a){
        cout<<"base string"<<endl;
    }
};
class der:public base{
    public:
    using base::func;  // use scope resolution operator
    void func(int a){
        cout<<"der func"<<endl;
    }
};
int main(){
    der d;
    d.func(99);
    string s="absk";
    d.func(s);
    return 0;
}