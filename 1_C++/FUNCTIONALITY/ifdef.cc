#include<iostream>
using namespace std;
#define DEBUG
#define dodo

void func1(){
    cout<<"debug mode"<<endl;
}
void func2(){
    cout<<"normal mode"<<endl;
}

int main(){
    #ifdef DEBUG  //ifdef elif else endif
    func1();
    #elif defined(dodo)
    func2();
    #else
    cout<<"none"<<endl;
    #endif
    return 0;
}
