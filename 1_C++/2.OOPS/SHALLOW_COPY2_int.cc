//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:
    int a;
    int* p;
    base(int a,int* p){
        this->a=a;
        this->p=p;
    }
    base(base& temp){
        a=temp.a;
        p=temp.p;
    }
    void print(){
        cout<<a<<" "<<*p<<endl;
    }
};
int main(){
    int *p=new int(500); //ok with main() but dont try with functions //scope limitation
    base b(100,p);
    base c(b);

    b.print();
    c.print();
    cout<<"--------"<<endl;
    int a=200;
    //c.p=&a; // deep copy
    *c.p=2000; //shallow copy;
    
    b.print();
    c.print();
    return 0;
}