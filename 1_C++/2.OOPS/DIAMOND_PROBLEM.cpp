#include<iostream>
using namespace std;
class A{
    public:
    A(){cout<<"this is A"<<endl;}
    void func(){
        cout<<"this is A func"<<endl;
    }
};
class B:virtual public A{
    public:
    B(){cout<<"this is B"<<endl;}
};

class C:virtual public A{
    public:
    C(){cout<<"this is C"<<endl;}
};
class D:public B,public C{
    public:
    D(){cout<<"this is D"<<endl;}
};

int main(){
    D obj;
    obj.func();
    cout<<"Completed"<<endl;
    return 0; 

}