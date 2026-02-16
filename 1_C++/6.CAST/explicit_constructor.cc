//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
class base{
    public:
     explicit base(int x){ //explicit to stop int->base conversion
        cout<<x<<endl;
    }
};
void fun(base ob){
}
int main(){
    fun(static_cast<base>(42));  //int->base   42->base ob
    return 0;
}