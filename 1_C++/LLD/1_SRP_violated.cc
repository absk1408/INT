//breaks SRP in cart class.
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
    const vector<product*> getproduct(){
        return move(v);
    }
    int calculatetotal(){
        int total=0;
        for(auto x:v){
            total+=x->price;
        }
        return total;
    }
    void printinvoice(){
        cout<<"Printing Invoice:"<<endl;
        for(auto x:v){
            cout<<"Product name:"<<x->name<<" "<<"price:"<<x->price<<endl;
        }
    }
    void savetodb(string name){
        cout<<"save to: "<<"SQL"<<endl;
    }
};
int main(){
    cart c;
    c.addproduct(new product("mobile",10001));
    c.addproduct(new product("laptop",50001));
    cout<<c.calculatetotal();
    c.printinvoice();
    return 0;
}