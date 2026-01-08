#include <iostream>
#include<memory>
using namespace std;
class base{ public:
int a;
    base(){
        cout<<"default base constructor"<<endl;
    }
    base(int a){
        this->a=a;
        cout<<"base created"<<endl;;
    }
 
    void fun(){
        cout<<"base funtion"<<endl;
    };
    virtual ~base(){
        cout<<"base destructor called"<<endl;

    }

};
class derived1: virtual public base{
    public:
    derived1(){
        cout<<"derived1 created"<<endl;
    }
    ~derived1(){
        cout<<"derived1 destructor called"<<endl;
    }
};
class derived2:virtual public base{
    public:
    derived2(){
        cout<<"der2 constructor"<<endl;
    }
    ~derived2(){
        cout<<"derived2 derstructor called"<<endl;
    }
};
class child: public derived1, public derived2{
    public:
   child(){
    cout<<"child created"<<endl;
   }
    ~child(){
        cout<<"child destructor called"<<endl;

    }
};
int main(){
    child *c1=dynamic_cast<child*>(new base());
    if(c1) cout<<"hello"<<endl;
    delete c1;
}