//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void func2(int & arg){
    cout<<"lvalue"<<endl;
}
void func2(int && arg){
    cout<<"rvalue"<<endl;
}
template<typename T>
void func1(T && arg){
    cout<<arg<<endl;
    func2(forward<T>(arg));
    //func2(arg);
}
int main(){
    int a=110;
    func1(a);
    func1(100);
    return 0;
}