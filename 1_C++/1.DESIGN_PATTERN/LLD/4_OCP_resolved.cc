//resolve SRP_resolved cause we cant add a new function to save db 
//so we can create a new module
//resolves SRP in cart class.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class product{
    public:
    string name;
    int price;
    product(string n,int p):name(n),price(p){}
};
class cart{
    vector<product*> v;
    public:
    void addproduct(product* p){
        v.emplace_back(p);
    }
    const vector<product*>getproduct(){
        return move(v);
    }
    int calculatetotal(){
        int total=0;
        for(auto x:v){
            total+=x->price;
        }
        return total;
    }
};
class printinvoice{
    cart* c;
    public:
    printinvoice(cart* cc):c{cc}{}
    void print_invoice(){
        cout<<"Printing Invoice:"<<endl;
        for(auto x:c->getproduct()){
            cout<<"Product name:"<<x->name<<" "<<"price:"<<x->price<<endl;
        }
    }
};
class database{
    public:
    cart* c;
    public:
    virtual void saveto(string name)=0;
};

class savingtosql:public database{
    public:
    savingtosql(cart* cc){
        c=cc;
    }
    void saveto(string name){
        cout<<"save to: "<<"SQL"<<endl;
    }
};
class savingtofile:public database{
    public:
    savingtofile(cart* cc){
        c=cc;
    }
    void saveto(string name){
        cout<<"save to: "<<"file"<<endl;
    }
};
int main(){
    cart c;
    c.addproduct(new product("mobile",10001));
    c.addproduct(new product("laptop",50001));
    printinvoice pi(&c);
    pi.print_invoice();
    database* db=new savingtosql(&c);
    db->saveto("sql");
    database* file=new savingtofile(&c);
    file->saveto("file");

    
    
    return 0;
}