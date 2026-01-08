//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
//
int main(){
    shared_ptr<int> ptr=make_shared<int>(10);
    weak_ptr<int> ptr2=ptr;
    shared_ptr<int> ptr3=ptr2.lock();
    cout<<ptr.use_count()<<endl;
    return 0;
}