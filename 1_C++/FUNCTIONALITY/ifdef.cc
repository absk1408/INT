#include<iostream>
using namespace std;
#define DEBUG

void func1(){
    cout<<"debug mode"<<endl;
}
void func2(){
    cout<<"normal mode"<<endl;
}

int main(){
    #ifdef DEBUG  //ifdef elif else endif
    func1();
    #else
    func2();
    #endif
    return 0;
}
