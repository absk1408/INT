//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
#include<cstdlib>
using namespace std;
class base{
    public:
    int *a;
    base(int a){
        this->a=new int(a);
        cout<<"base called"<<endl;
    }
    void* operator new(size_t size){
        void* p=malloc(size);
        if(!p) throw bad_alloc();
        return p;
    }
    ~base(){
        delete a;
        cout<<"base destructor called"<<endl;
    }
};
class derived1:public base{
    public:
    derived1(int a):base(a){
        cout<<"derived1 called"<<endl;
    }
    ~derived1(){
        cout<<"der1 destructor called"<<endl;
    }
};
class derived2:virtual public base{
    public:
    derived2(int a):base(a){
        cout<<"derived2 called"<<endl;
    }
    ~derived2(){
        cout<<"der2 destructor called"<<endl;
    }
};
class child:public derived2{
    public:
    child(int a):base(a),derived2(a){
        cout<<"child called"<<endl;
    }
    ~child(){
        cout<<"child destructor called"<<endl;
    }
};
int main(){
    child c1(100);
    return 0;
}