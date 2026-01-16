//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:int a;
};
class der:public base{  //private base{  not allowedd
    
};
int main(){
    base *b1=new der();

    return 0;
}