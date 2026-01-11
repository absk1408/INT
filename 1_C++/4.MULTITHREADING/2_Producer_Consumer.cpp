//#include<bits/stdc++.h>
#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>
using namespace std;
mutex mtx;condition_variable cv; bool flag=true;
queue<int> buffer;const int limit=5;
void consumer(){
    while(true){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[](){return !buffer.empty();});
        while(!buffer.empty()){
            cout<<buffer.front()<<endl;
            buffer.pop();
        }
        lock.unlock();
        cv.notify_all();
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}
void producer(){
    int data=0;
    while(true){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[](){return buffer.size()<limit;});
        while(buffer.size()<limit){
            buffer.push(data++);
        }
        lock.unlock();
        cv.notify_all();
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

int main(){
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}