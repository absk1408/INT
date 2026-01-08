#include <stdio.h>
#include<iostream>
using namespace std;

typedef void(*PF)();
void func1(){
    cout<<("Plugin A executed\n")<<endl;
}
void func2(){ 
    cout<<("Plugin B executed\n")<<endl; 
}
void func3(PF plugins[], int count) {
    for (int i = 0; i < count; ++i)
        plugins[i]();
}
int main() {
    PF arr[2]={func1,func2};
    func3(arr,2);

    return 0;
}
