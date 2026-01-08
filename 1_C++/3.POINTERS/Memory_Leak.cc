//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
void memoryleak(){
    while(true){
        int * ptr=new int[1000];
        cout<<"allocated"<<endl;
        //delete []ptr; to save from memory leak we have to delete
        //here ptr which is in stack will be delted and then we have stale memory which is there in heap
        // and no one can use this heap leads to, memory leaks.
    }
}
int main(){
    memoryleak();
    return 0;
}