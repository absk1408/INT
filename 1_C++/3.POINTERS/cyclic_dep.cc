//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
class b;
class a{
    public: 
    weak_ptr<b> bptr;
    //shared_ptr<b> bptr; //cylic dep issue
};
class b{
    public:
    shared_ptr<a> aptr;
};
int main(){
    shared_ptr<a> s=make_shared<a>();
    shared_ptr<b> v=make_shared<b>();
    
    s->bptr=v;
    v->aptr=s;
    //cout<<s.use_count()<<endl;
    //cout<<v.use_count()<<endl;
    cout<<s->bptr.use_count()<<endl;
    cout<<v->aptr.use_count()<<endl;




    

    
    return 0;
}