//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
//
int main(){
    shared_ptr<int> ptr=make_shared<int>(10);
    shared_ptr<int> ptr2=ptr;
    cout<<ptr.use_count()<<endl;
    ptr.reset();
    cout<<ptr.use_count()<<endl;
    cout<<ptr2.use_count()<<endl;
    ptr2.reset();
    cout<<ptr2.use_count()<<endl;
    shared_ptr<int*> s;
    return 0;
}