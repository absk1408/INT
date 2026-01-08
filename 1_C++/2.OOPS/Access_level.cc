//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:
    int x;
    base(int a):x(a){
        cout<<"im in base"<<endl;
    }

};
class der:private base{
    public:
    der(int a):base(100){  //but can access in derived
        cout<<"im in derived"<<x<<endl;  
    }
};

int main(){
    der d(100);
    //cant access here
    return 0;
}