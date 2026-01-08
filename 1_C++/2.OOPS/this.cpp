//same parameter names as data members
//chain functions
//we can not change "this" pointer after initialization
#include<iostream>
using namespace std;

class Point{
    
    public:
    int x, y;
        Point(int x, int y){
            this -> x = x;
            this -> y = y; 
           cout<<"------"<<endl;
            cout<<&x<<" "<<&y<<endl; //parameters
            cout<<&(this->x)<<" "<<&(this->y)<<" "<<&(*this)<<" "<<this<<endl; 
            //cout<<&this  :gives error as it is rvalue (a temporary created pointer by the compiler)
            cout<<"------"<<endl;
    }
};

int main(){
    Point p1(10, 10);
    cout<<&(p1)<<endl;
    ////////////////
    cout<<"############"<<endl;
    int x=100;
    int *p=&x;
    int &r=*p; //ref
    cout<<r<<endl;
    r=500;
    cout<<x<<endl; //new value
    return 0;

}