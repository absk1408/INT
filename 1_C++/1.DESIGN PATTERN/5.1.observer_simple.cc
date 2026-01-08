//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//subject
class client{ public:
    virtual void update(string message)=0;
    ~client()=default;
};
class client1:public client{
    
    public:string n;
    client1(string name){
        n=name;
        cout<<name<<" client is created"<<endl;
    }
    void update(string message){
        cout<<n<<message<<endl;
    }
};


class server{ public:
    virtual void add_client(client1 &c)=0;
    //virtual void delete_client(client &c)=0;
    virtual void notify(client1 &c)=0;
};
class myserver:public server{
    public:
    vector<client1> v;
    void add_client(client1 &c){
        v.push_back(c);
        cout<<c.n<<" is  pushed"<<endl;
    }
    void notify(client1 &c){
        c.update(" is updated");
    }
    void broadcast(){
        for(auto c:v){
            notify(c);
        }
    }
    //void delete_node()




};


int main(){
    client1 sn("storage node");
    client1 dn("data node");
    myserver s;
    s.add_client(sn);
    s.add_client(dn);
    s.notify(dn);
    s.broadcast();




    return 0;
}