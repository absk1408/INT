//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:   //private  then cant be acccess in derived
    int x;
    base(int a):x(a){
        cout<<"im in base"<<endl;
    }

};
class der:private base{
    public:
    der(int a):base(x){  //but can access in derived
        cout<<"im in derived"<<x<<endl;  
    }
};

int main(){
    der d(100);
    //cant access here
    return 0;
}