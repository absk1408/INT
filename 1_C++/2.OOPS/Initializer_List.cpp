#include<iostream>
using namespace std;
//class
class Test{
    int x;
    public:
    Test(){
        cout<<"default"<<'\n';
    }

    Test(int y){
        cout<<"parameter "<<'\n';
    }
};
class func{
    Test t;
    public:
    func():t(10){  //if we not initalize the base class in initalizer list then default 
            //constructor get called of the base class
       // t=Test(100);
    }
   //func():t(1900){}
};

int main(){
    func m;
    return 0;
}