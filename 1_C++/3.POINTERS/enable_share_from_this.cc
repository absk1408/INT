//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
class base:public enable_shared_from_this<base>{
    public:
    shared_ptr<base> getPTR(){
        return shared_from_this();
    }
};
int main(){
    //base b1;
    //shared_ptr<base> sp=b1.getPTR(); 
    //it only worked on object created through the shared_ptr ..
    

    shared_ptr<base> sp=make_shared<base>();
    shared_ptr<base> sp2=sp->getPTR();
    cout<<sp2.use_count()<<endl;
    return 0;
}