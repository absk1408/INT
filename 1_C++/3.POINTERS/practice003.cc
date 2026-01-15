//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
 int& func(){
    int a=100;
    return a;
 }
int main(){
    int &b=func();     //-//: incorrect as it is having a deleted address
    cout<<b<<endl;  
    return 0;
}