#include<iostream>
#include<memory>
using namespace std;
class client{
    public:
    virtual void connect()=0;
};
class dn:public client{
    public:
    void connect(){
        cout<<"dd connected"<<endl;
    }
};
class sn:public client{
    public:
    void connect(){
        cout<<"sn connected"<<endl;
    }
};
class factory{
    public:
    static unique_ptr<client> create(string name){
        if(name=="dn"){
            return make_unique<dn>();
        }
        if(name=="sn"){ 
            return make_unique<sn>();
        }
        return nullptr;
    }
};
class server{
    public:
    void handle(string name){
        unique_ptr<client> ptr=factory::create(name);

    if(ptr){
        ptr->connect();
    }
    else{
        cout<<"unknown client"<<endl;
    }
    }
};
int main(){
    server s;
    s.handle("dn");
}