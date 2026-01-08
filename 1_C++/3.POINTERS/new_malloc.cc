//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
//
int main(){
    unique_ptr<int> uptr (new int(42));
    cout<<*uptr<<endl;
    return 0;
}