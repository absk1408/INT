//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector> 
#include<mutex>
#include<thread>
#include<condition_variable>
using namespace std;
class semaphores{
    int counter;
    mutex mtx;
    condition_variable cv;
    public:
    semaphores(int value=1){
        counter=value;
    }
    void wait(){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[this](){return counter>0;});//wehenever you use data memeber in lambda always use "this"
        --counter;
    }
    void signal(){
        {
            unique_lock<mutex> lock(mtx);
            ++counter;
        }
        cv.notify_one();   // 🔥 important
    }
};
semaphores sm;
void func(int id){
    sm.wait();
    //do work;
    sm.signal();
}
int main(){
    vector<thread> arr;
    for(int i=0;i<10;i++){
        arr.emplace_back(func,i);
    }
    for(auto& t :arr){
        t.join();
    }
    return 0;
}