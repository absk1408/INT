//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//
int main(){
    void *ptr=malloc(1);
    *ptr=1;
    int* iptr=(int*) ptr;
    cout<<*iptr<<endl;

    return 0;
}