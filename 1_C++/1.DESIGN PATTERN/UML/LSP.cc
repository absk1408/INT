//breaks LSP
#include<iostream>
#include<vector>
using namespace std;
class account{
    public:
    virtual void deposit(int)=0;
    virtual void withdraw(int)=0;
};
class current:public account{
    int balance;
    public:
    current(int x):balance(x){}
    void deposit(int x){
        balance+=x;
    }
    void withdraw(int x){
        balance-=x;
    }
};
class saving:public account{
    int balance;
    public:
    saving(int x):balance(x){}
    void deposit(int x){
        balance+=x;
    }
    void withdraw(int x){
        balance-=x;
    }
};
class fixedd:public account{
    int balance;
    public:
    fixedd(int x):balance(x){}
    void deposit(int x){
        balance+=x;
    }
    void withdraw(int x){
        throw logic_error("we cant do it here");
    }
};

class bankclient{
    vector<account*>v;
    public:
    bankclient(vector<account*> vv):v(vv){}
    void transaction(){
        for(auto x:v){
            x->deposit(100);
            try{
                x->withdraw(100);
            }catch(const logic_error &e){
                cout<<e.what()<<endl;
            }
        }
    }
};
int main(){
    vector<account*> vv;
    vv.push_back(new current(500));
    vv.push_back(new saving(500));
    vv.push_back(new fixedd(500));
    bankclient* b=new bankclient(vv);
    b->transaction();
    return 0;
}