// /The Factory Pattern in C++ is a creational design pattern that provides a way to create objects without exposing the creation logic to the client, and it lets you decide the object type at runtime.
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
class Client{ public:
    virtual void connect() const=0;
    virtual ~Client(){};
};
class dd:public Client{ public:
    void connect()const override{
        cout<<"im DD"<<endl;
    }
};
class ndmp:public Client{ public:
    void connect()const override{
        cout<<"im NDMP"<<endl;
    }
};
class clientfactory{
    public:
    static unique_ptr<Client> createclient(const string& name){
        if(name=="dd") return make_unique<dd>();
        if(name=="ndmp") return make_unique<ndmp>();
        return nullptr;
    }
};
class Server{
    public:
    void handleclient(const string& clienttype){
        unique_ptr<Client>c=clientfactory::createclient(clienttype);
        if(c) c->connect();
        else{
            cout<<"unknown client"<<endl;
        }
    }
};

int main(){
    Server s;
    s.handleclient("ndmp");
    s.handleclient("dd");
    return 0;
}