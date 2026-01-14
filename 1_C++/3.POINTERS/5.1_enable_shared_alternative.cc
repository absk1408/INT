//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
class base{
    public:
    int a;
    base(int b){
        a=b;
    }
};
int main(){
    shared_ptr<base> ptr=make_shared<base>(1000);
    cout<<ptr->a<<endl;
    shared_ptr<base> ptr2=ptr;
    cout<<ptr2->a<<endl;
    return 0;
}

//this will work but in any case if you want to go for "this" pointer or want to play woth it then it will not be sufficient.