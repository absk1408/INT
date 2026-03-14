#include<iostream>
using namespace std;

int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int main(){
    int(*func) (int ,int);
    func=add;
    cout<<func(200,100)<<endl;

    func=sub;
    cout<<func(200,100)<<endl;
    return 0;
}