//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
class base{
    public:
    shared_ptr<base> getPTR(){
        return shared_ptr<base>(this);
    }
};
int main(){
    base b1;
    shared_ptr<base> ptr2=b1.getPTR();  //issue is going to be double delete once the program wil end
    return 0;
}

