//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
#include<mutex>
#include<thread>
using namespace std;
//
int main(){
    weak_ptr<int> wptr;
    mutex mtx;
    shared_ptr<int> sp=make_shared<int>(100);
    wptr=sp;
    auto lam=[&](){
        shared_ptr<int>locked;
        {
            lock_guard<mutex> lock(mtx);
            locked=wptr.lock();
        }
        if(locked){  //very important
            *locked=99;
        }
        
    };
    thread t1(lam);
    auto lam2=[&](){
        lock_guard<mutex> lock(mtx);
        sp.reset();
    };
    thread t2(lam2);
    t1.join();
    t2.join();
    return 0;
}