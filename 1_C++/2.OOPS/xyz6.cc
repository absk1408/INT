//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
#include<cstdlib>
using namespace std;
//
int main(){

    //unique_ptr<void,void(*)(void*)>uptr(malloc(sizeof(int)),free);
    //*static_cast<int*>(uptr.get())=100;
    //cout<<*static_cast<int*>(uptr.get())<<endl;
    unique_ptr<int>uptr(new int(10));
    cout<<*uptr<<endl;
    
    return 0;
}
