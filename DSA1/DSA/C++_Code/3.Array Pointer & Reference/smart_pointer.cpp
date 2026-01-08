//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
template<class T> class s_ptr{
    public:
    T* ptr;
    explicit s_ptr(T*p=NULL){
        ptr=p;
    }
    ~s_ptr(){
        delete(ptr);
    }
    T& operator*(){
        return *ptr;
    }
    T* operator->(){
        return ptr;
    }
};
int main(){
  
    s_ptr<int> ptr(new int());
    *ptr=100;
    cout<<*ptr;



    return 0;
}