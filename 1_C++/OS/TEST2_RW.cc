//wrong output , not as expected but good for practice.
#include<iostream>
#include<algorithm>
#include<thread>
#include<mutex>
#include<shared_mutex>
#include<condition_variable>
using namespace std;
shared_mutex m1;
mutex m2;
condition_variable_any cv; bool flag=false;
int ss=3;
void printarr(int arr[],int n){
    static int f=0; f++;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    if(f==2){
        flag=false;
        cv.notify_one();
        f=0;
    }

}
void readfun(int arr[]){
    while(--ss){
    shared_lock<shared_mutex> sl(m1);
    cv.wait(sl,[] {return flag;});
    m2.lock();
    printarr(arr,10);
    m2.unlock();
    }
}
void writefun(int arr[],int num){
    
    while(true){
    unique_lock<shared_mutex> ul(m1);
    for(int i=0;i<num;i++){
        if(i==0){
            arr[i]=i; continue;
        }
        if(i%10==0){
            flag=true;
            cv.notify_all();
            cv.wait(ul,[]{ return !flag;});
        }
        arr[i%10]=i;
    }
    flag=true;
    cv.notify_all();

    }

}

int main(){
    int arr[10]={0}; int n=100;
    thread writer(writefun,arr,n);
    thread reader1(readfun,arr);
    thread reader2(readfun,arr);
    writer.join();reader1.join();reader2.join();
    return 0;
}