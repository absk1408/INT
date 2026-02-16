#include<iostream>
using namespace std;
void fun(int *x1,int *y1){
    cout<<&(*x1)<<"->"<<*x1<<" ";   //also x1 is equal to &(*x)
    cout<<&(*y1)<<"->"<<*y1<<endl;
}
int main(){
    int x;int y;
    x=10;y=20;
    cout<<&x<<"->"<<x<<" ";
    cout<<&y<<"->"<<y<<endl;
    fun(&x,&y);
}