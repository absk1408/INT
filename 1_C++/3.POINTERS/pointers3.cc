//ABHISHEK YADAV/absk1408
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct S {
    int x = 99;
};

S s;        // global object
S* p = &s; // pointer to s

int main() {
    p->x = 10;  // assign through pointer
}
