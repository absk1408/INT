//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:
    ~base(){
        cout<<"base destructor called"<<endl;
    }
};
class der:public base{ public:
    ~der(){
        cout<<"derived destructor called"<<endl;
    }
};
int main(){
    der d;
    base* b=&d;
    delete b;
    return 0;
}