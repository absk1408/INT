#include<iostream>
#include<algorithm>
using namespace std;
int fun(){
    int a=100;
    return a;
}
//can do return by copy
int main(){
    int a=fun();
    return 0;
}