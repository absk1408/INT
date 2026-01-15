//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class write{
    static write* instance;
    write(){cout<<"singleton created"<<endl;}
    write(const write& temp)=delete;
    write& operator=(const write& temp)=delete;
    public:
    static write* getinstance(){
        if(!instance){
            cout<<"successfull"<<endl;
            instance=new write();
        }
        else{
            cout<<"busy"<<endl;
        }
        return instance;

    }
};

write* write::instance=nullptr;

class server{
    public:
    void handlereq(){
        write* ptr=write::getinstance();    //no need of object creation.
        
    }
};
int main(){
    server s;
    s.handlereq();
    server s2;
    s2.handlereq();
    return 0;
}