#include<iostream>
#include<memory>
using namespace std;
int main(){
    unique_ptr<int> uptr=make_unique<int>(10);
}