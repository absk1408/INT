//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class base{
    public:
    base(){
        cout<<"base called"<<endl;
    }
    virtual ~base(){  //one funtion should be virtual
        cout<<"destructor called"<<endl;
    }
};
class derived:public base{
    public:
    derived(){
        cout<<"derived class"<<endl;
    }
    ~derived(){
        cout<<"derived called"<<endl;
    }
};
int main(){
    //base *b1=static_cast<base*>(new base); //failure
    base *b1=static_cast<base*>(new derived); //upcasting  //Success: new derived 
    base *der=dynamic_cast<derived*>(b1); //downcasting
    if(!der){   //return nullptr in failure
        cout<<"failure (pointer)"<<endl;
    }
    else{
        cout<<"succcess(pointer)"<<endl;
    }

    try{
        base &der2=dynamic_cast<derived&>(*b1); //downcasting refernce
    }
    catch(const bad_cast &e){
        cout<<e.what()<<endl;
        return 0;
    }
    cout<<"success (refernce)"<<endl;
    return 0;
}