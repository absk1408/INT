//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class custom_new{
    public:
    custom_new()=default;
    ~custom_new()=default;
    void* operator new(size_t val){
        void *ptr=malloc(val*2);
        if(!ptr) throw bad_alloc(); 
        return ptr;
    }
};
int main(){
    custom_new *ptr=new custom_new();
    int *ptr=new int(10);
    cout<<sizeof(*ptr)<<endl;
    return 0;
}