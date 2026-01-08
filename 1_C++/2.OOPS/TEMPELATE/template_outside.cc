//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
template<typename T>
class base{
    public:
    void func();
};
template<typename T>
void base<T>::func(){
    cout<<"declare the function outside the class"<<endl;
}
int main(){
    base<int>b;
    b.func();
    return 0;
}