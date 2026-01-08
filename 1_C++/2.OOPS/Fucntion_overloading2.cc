//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{ public:
int a;
    base(int a){
        this->a=a;
    }
    void func()const{ //error:without const 
        cout<<a<<endl;
    }
   
};
int main(){
    const base b(100);
    cout<<b.a<<endl;
    b.func(); 
  
    return 0;
}