///IMPORTANT
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:
    int a=100;
    int * ptr=new int(99);
    base(){
        cout<<"base created"<<endl;
    }
};
int main(){
    base b;
    //cout<<b->a<<endl;
    cout<<*b.ptr<<endl; 
    //cout<<b->ptr<<endl; //error
    base *b2=new base();
    cout<<b2->a<<endl;
    cout<<*(b2->ptr)<<endl;
    cout<<*(*b2).ptr<<endl;  //  first we go inside the () then . is having higher precedence then *
//
    
    return 0;
}