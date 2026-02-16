//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class Cexception{
    string message;
    public:
    Cexception(const string& msg):message(msg){}
    string& get(){
        return message;
    }
};
void func(){
    throw Cexception("i am not in mood to execute");
}
int main(){
    try{
        func();
    }catch(Cexception& m){
        cout<<m.get()<<endl;
    }
    return 0;
}