//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<thread>
using namespace std;
void func(int *a){
    *a=*a+100;
}
int main(){
    int a=100;
    int *ptr=&a;

    thread t3(func,ptr);
    t3.join();
    cout<<*ptr<<endl;

    return 0;
}