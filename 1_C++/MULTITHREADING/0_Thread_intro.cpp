#include<iostream>
#include<thread> //header//
using namespace std;
int fun(int a){
    cout<<++a<<endl;
    return a++;
}
class A{
    public:
    A(){
        cout<<"default"<<endl;
    }
    A(int a){
        cout<<"im in"<<a<<endl;
    }
    void operator()(){
        cout<<"im a bracket "<<endl;
    }
    void fun1(int a){
        cout<<"hellow"<<a<<endl;
    }
    static void fun2(int a){
        cout<<"static member function with "<<a<<endl;
    }
};

auto f=[](int a){
    cout<<"im in lambda"<<a<<endl;
};
int main(){
    thread ob(fun,10);
    ob.join();

    thread ob2(A{});
    ob2.join();

    A a1;
    thread ob3(&A::fun1,&a1,100);
    ob3.join();

    thread ob4(&A::fun2,2000);
    ob4.join();
    return 0;
}