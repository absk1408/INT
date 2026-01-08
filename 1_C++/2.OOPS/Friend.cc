//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    int a=100;
    friend void func(base &b);
};
void func(base &b){
    cout<<b.a<<endl;
}
int main(){
    base b;
    func(b);
    return 0;
}