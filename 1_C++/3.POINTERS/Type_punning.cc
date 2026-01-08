//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//
int main(){
    float f=10.0f;
    int* i=(int*)&f;
    cout<<*i<<endl;

    int i2;
    memcpy(&i2,&f,sizeof(int));
    cout<<i2<<endl;
    return 0;
}