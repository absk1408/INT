//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<memory>
using namespace std;
//
int main(){
    unique_ptr<int> uptr (new int(42));  //error-prone
    cout<<*uptr<<endl;
    return 0;
}
/*
Now imagine:
new int(5) allocates memory
Before unique_ptr constructor runs
An exception occurs
➡️ The raw pointer is lost
➡️ Memory leak 
*/