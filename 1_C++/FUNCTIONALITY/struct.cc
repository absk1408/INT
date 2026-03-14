//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct str{
    int a;
   str(int a){
        this->a=a;
   }
   void print(){
    cout<<a<<endl;
   }
};
int main(){
    str a1(99);
    a1.print(); 
    //or
    str p(190);  // correct object construction with argument
    p.print(); 

    return 0;
}