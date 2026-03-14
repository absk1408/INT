//#include<bits/stdc++.h>
//A functor (function object) is an object that behaves like a function.
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:
    int operator()(int a,int b){
        cout<<"hello im a functor"<<endl;
        return a+b;
    }
}; //overloads the () and use object as a function
int main(){
    base b;
    cout<<b(100,200);
    return 0;
}