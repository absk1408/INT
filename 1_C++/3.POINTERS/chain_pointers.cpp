//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//
int main(){
    int a=100;
    int *p=&a;
    int **p2=&p;
    cout<<**p2<<endl;
    int ***p3=&p2;
    cout<<***p3<<endl;
    int ****p4=&p3;
    cout<<****p4<<endl;
    ****p4=99;
    cout<<*p<<" "<<**p2<<" "<<***p3<<" "<<****p4<<endl;
    return 0;
}