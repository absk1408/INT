//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
template<class T>
class SP{  //unique_ptr
    T* ptr;
    public:
    SP(T* p){
        ptr=p;
    }
    ~SP(){delete ptr;}
    //unique ptr
    SP(const SP&)=delete;
    SP& operator=(const SP&)=delete;

    T& operator*(){
        cout<<"im * operator"<<endl;
        return *ptr;
    }
    T* operator ->(){
        return ptr;
    }
    SP(SP&& temp){
        ptr=temp.ptr;
        temp.ptr=nullptr;
    }
    SP& operator=(SP&& temp){
        if(this==&temp) return *this;
        delete ptr;
        ptr=temp.ptr;
        temp.ptr=nullptr;
        return *this;
    }
    void reset(){
        delete ptr;
        ptr=nullptr;
    }
};
int main(){
    SP<int> up(new int (10));
    cout<<*up<<endl;
    return 0;
}