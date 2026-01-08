//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<thread>
#include<future>
using namespace std;
void func(promise<int> myprom,int n){
    int result=0;
    for (int i = 0; i < n; i++)
    {
        result+=i;
    }
    myprom.set_value(result);

    
}
int main(){
    promise<int> sum;
    int val=10;
    future<int> sumfuture=sum.get_future();
    thread t1(func,move(sum),val);
    cout<<sumfuture.get()<<endl;
    return 0;
}