#include<iostream>
using namespace std;
int main(){
    int a=123123;
    int c=a;
    int b=0;
    while(c){
        b=(b*10)+c%10;
        c/=10;
    }
    cout<<b;

}