//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

template <typename T1,typename T2>
class Box {
    T1 value;
    T2 value2;
public:
    Box(T1 v,T2 s){
        value=v;
        value2=s;

    }
    void show() { 
        cout << value << " ";
        cout<<value2<<endl; 
    }
};
int main(){
    Box<int,float> b1(10,20.100);
    Box b2("hello",101);

    b1.show();  // Outputs: 10
    b2.show();  // Outputs: Hello
    
    return 0;
}