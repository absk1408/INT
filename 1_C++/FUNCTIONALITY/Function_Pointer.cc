#include<iostream>
using namespace std;

int execute(int x,int y, int(*func1)(int,int)){
    cout<<"im in execute"<<endl;
    return func1(x,y);

}

int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
int main(){
    int(*func) (int ,int);
    func=add;
    cout<<execute(100,200,func)<<endl;

    func=sub;
    cout<<execute(100,200,func)<<endl;
    return 0;
}