//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{ public:
    int x;
    public:
    base(int x){
        this->x=x;
    }
    base operator+(base temp){
        cout<<"this is operator +"<<endl;
        return x+=temp.x;
    }
};

int main(){
    base b1(100);base b2(200);
    base b3=b1+b2;
    cout<<b3.x;
    return 0;
}