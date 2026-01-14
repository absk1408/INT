//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
//

struct S {
    int x=99;
};

S s;
S* p = &s;

int main(){
    //

p->x = 10;   // ❌ WRONG

    return 0;
}