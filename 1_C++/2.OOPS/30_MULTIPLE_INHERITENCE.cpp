#include<iostream>
using namespace std;
class A{
    public:
    A(){cout<<"this is A"<<endl;}
    void func(){
        cout<<"this is func of A"<<endl;
    }
};
class B{
    public:
    B(){cout<<"this is B"<<endl;}
    void func(){
        cout<<"this is func of B"<<endl;
    }
};
class C:public B,private A{
    public:
    C(){cout<<"this is C"<<endl;}
    
};

int main(){
    C obj;
    cout<<"hi "<<endl;
    obj.func();
    return 0; 

}