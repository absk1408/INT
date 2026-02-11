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
class savingtodb{
    cart* c;
    public:
    savingtodb(cart* cc):c(cc){}
    void savetodb(string name){
        cout<<"save to: "<<"SQL"<<endl;
    }
    void savetofile(string name){  // have to add the function 
        cout<<"saving to file"<<endl; // breaks OCP by modification
    }
};
int main(){
    cart c;
    c.addproduct(new product("mobile",10001));
    c.addproduct(new product("laptop",50001));
    savingtodb db(&c);
    db.savetodb("SQL");

    printinvoice pi(&c);
    pi.print_invoice();

    
    
    return 0;
}