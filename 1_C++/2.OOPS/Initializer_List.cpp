#include<iostream>
using namespace std;
//class
class Test{
    int x;
    public:

    Test(int y){
        cout<<"parameter "<<'\n';
    }
};
class func{
    Test t;
    public:
    func(){  //if we not initalize the base class in initalizer list then default 
            //constructor get called of the base class
        t=Test();
    }
   //func():t(1900){}
};

int main(){
    func m;
    return 0;
}