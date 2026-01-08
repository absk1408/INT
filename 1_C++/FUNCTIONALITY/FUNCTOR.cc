//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:
    void operator()(){
        cout<<"hello im a functor"<<endl;
    }
}; //overloads the () and use object as a function
int main(){
    base b;
    b();
    return 0;
}